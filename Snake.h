#pragma once
#include "HCN.h"
#include "TRON.h"
#define D 25

class Snake
{
public:
	HCN head;
	TRON tail[100];
	int n;
	int add;
	Snake();
	Snake(int _x, int _y);
	void drawHinh(CClientDC* pdc);
	void Left();
	void Right();
	void Up();
	void Down();
	void swapPos();
	void addTail();
	int checkTouchTail();
};

