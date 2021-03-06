// GGO.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <thread>
#include <Windows.h>
#include <iostream>
#include <mutex>
#include <graphics.h>      
#include <conio.h>
#include <cmath>
#include <random>

const static int MAXLENGTH = 1280;
const static int MAXWIDE = 720;

//std::mutex mue;

static int score = 0;
static int show = 0;
static int thisx, thisy, thisr;
static int add = 1;
static bool hit = false;
static MOUSEMSG m;
static bool start = true;

int r=15;
int s=600;

void magnify(int x, int y, int r,int s) {
	//int n = s/r;
	thisr = r;
	for (int i = 0; i <=r; i++) {
		fillcircle(x, y, i);
		//thisr = i;
		Sleep(s/r);
		clearcircle(x, y,i + 1);
		//cleardevice();
	}
	for (int i = r; i >0 ; i--) {
		fillcircle(x, y, i);
		Sleep(s / r);
		clearcircle(x, y, i + 1);
		//cleardevice();
	}
}

/*void magnify(int x, int y, int r, int s) {
	//thisr = r;
	fillcircle(x, y, r);
	Sleep(s);
	cleardevice();
}*/

void check() {
	while (1) {
		m = GetMouseMsg();
		hit = ((m.uMsg == WM_LBUTTONDOWN || m.uMsg == WM_LBUTTONUP) && m.mkLButton == true && (pow(m.x - thisx, 2) + pow(m.y - thisy, 2) <= pow(thisr, 2)));
		if (hit) {
			score++;
			//add = 1;
			std::cout << "\a";
		}
		if (m.uMsg == WM_RBUTTONDOWN) {
			start = false;
			break;
		}
	}
}

void draw() {
	std::mt19937 rng;
	while (start) {
		rng.seed(std::random_device()());
		std::uniform_int_distribution<std::mt19937::result_type> distx(r, MAXLENGTH - r);
		std::uniform_int_distribution<std::mt19937::result_type> disty(r, MAXWIDE - r);
		thisx = distx(rng);
		thisy = disty(rng);
		show++;
		magnify(thisx, thisy,r,s);
	}
}

int main()
{

	initgraph(MAXLENGTH, MAXWIDE, SHOWCONSOLE);
	std::thread Dth(draw);
	std::thread Cth(check);
	thisr = r;

	Dth.join();
	Cth.join();

	closegraph();

	std::cout << show <<"次"<< "命中了" << score <<"个，命中率为"<< (double)score/show*100.0<<'%'<< std::endl;

	_getch();
	
    return 0;
}

