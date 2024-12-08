#include "pch.h"
#include "Snake.h"

Snake::Snake()
{
	add = 0;
	int _x = 0, _y = 0;
	n = 1;
	head = HCN(_x, _y, _x + D, _y + D);
	tail[0] = TRON(head.x1, head.y2, head.x1 + D, head.y2 + D);
}

Snake::Snake(int _x, int _y)
{
	add = 0;
	n = 1;
	head = HCN(_x, _y, _x + D, _y + D);
	tail[0] = TRON(head.x1, head.y2, head.x1 + D, head.y2 + D);

}

void Snake::drawHinh(CClientDC* pdc)
{
	// T?o brush và pen cho ??u r?n
	CBrush headBrush(RGB(255, 165, 0)); // Màu cam cho ??u r?n
	CPen headPen(PS_SOLID, 1, RGB(0, 0, 0)); // Vi?n ?en dày 1 pixel

	// L?u l?i brush và pen c?
	CBrush* oldBrush = pdc->SelectObject(&headBrush);
	CPen* oldPen = pdc->SelectObject(&headPen);

	// V? ??u r?n
	head.drawHinh(pdc);

	// Khôi ph?c l?i brush và pen c?
	pdc->SelectObject(oldBrush);
	pdc->SelectObject(oldPen);

	// V? t?ng ph?n t? c?a ?uôi r?n v?i màu s?c khác nhau
	for (int i = 0; i < n; i++)
	{
		// T?o brush v?i màu s?c khác nhau cho t?ng ph?n t?
		int red = (rand() % 256);
		int green = (rand() % 256);
		int blue = (rand() % 256);
		CBrush tailBrush(RGB(red, green, blue));

		// L?u l?i brush c?
		oldBrush = pdc->SelectObject(&tailBrush);

		// V? ph?n t? ?uôi
		tail[i].drawHinh(pdc);

		// Khôi ph?c l?i brush c?
		pdc->SelectObject(oldBrush);
	}

	// Khôi ph?c l?i pen c?
	pdc->SelectObject(oldPen);
}

void Snake::Left()
{
	swapPos();
	head.Left(D);
}

void Snake::Right()
{
	swapPos();
	head.Right(D);
}

void Snake::Up()
{
	swapPos();
	head.Up(D);
}

void Snake::Down()
{
	swapPos();
	head.Down(D);
}

void Snake::swapPos()
{
	if (add == 1)
	{
		n++;
		add = 0;
	}
	for (int i = n - 1; i > 0; i--)
	{
		tail[i].x1 = tail[i - 1].x1;
		tail[i].y1 = tail[i - 1].y1;
		tail[i].x2 = tail[i - 1].x2;
		tail[i].y2 = tail[i - 1].y2;
		tail[i].tamTron();
	}
	tail[0].x1 = head.x1;
	tail[0].y1 = head.y1;
	tail[0].x2 = head.x2;
	tail[0].y2 = head.y2;
	tail[0].tamTron();
}

void Snake::addTail()
{
	add = 1;
}

int Snake::checkTouchTail()
{
	int _x = (head.x1 + head.x2) / 2;
	int _y = (head.y1 + head.y2) / 2;
	CPoint p = CPoint(_x, _y);
	for (int i = 0; i < n; i++) 
	{
		if (tail[i].checkHinh(p) == 1)
			return 1;
	}
	return 0;
}
