#include "pch.h"
#include "TRON.h"

void TRON::tamTron()
{
	o.x = (x1 + x2) / 2;
	o.y = (y1 + y2) / 2;
	int rx = (x2 - x1) / 2;
	int ry = (y2 - y1) / 2;

	if (rx < ry) r = rx;
	else r = ry;
}

void TRON::drawHinh(CClientDC* pdc)
{
	pdc->Ellipse(o.x - r, o.y - r, o.x + r, o.y + r);
}
