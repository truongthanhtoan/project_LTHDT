#pragma once
#include "Hinh.h"
class TRON :
    public Hinh
{
public:
    int r;
    CPoint o;
    TRON():Hinh()
    {
        r = 0;
        o.x = 0;
        o.y = 0;
    }
    TRON(int _x1, int _y1, int _x2, int _y2):Hinh(_x1, _y1, _x2, _y2)
    {
        tamTron();
    }
    void tamTron();
    void drawHinh(CClientDC* pdc);
};

