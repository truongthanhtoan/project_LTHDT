#pragma once
class Hinh
{
public:
	int x1, y1, x2, y2;
	Hinh()
	{
		x1 = 0; 
		y1 = 0;
		x2 = 0;
		y2 = 0;
	}
	Hinh(int _x1, int _y1, int _x2, int _y2)
	{
		x1 = _x1;
		y1 = _y1;
		x2 = _x2;
		y2 = _y2;
	}

	void virtual drawHinh(CClientDC* pdc)
	{
		return;
	}

	void virtual Left(int d)
	{
		x1 = x1 - d;
		x2 = x2 - d;
	}
	void virtual Right(int d)
	{
		x1 = x1 + d;
		x2 = x2 + d;
	}
	void virtual Up(int d)
	{
		y1 = y1 - d;
		y2 = y2 - d;
	}
	void virtual Down(int d)
	{
		y1 = y1 + d;
		y2 = y2 + d;
	}

	int virtual checkHinh(CPoint p)
	{
		if (p.x > x1 && p.x < x2 && p.y > y1 && p.y < y2)
			return 1;
		else return 0;
	}
};

