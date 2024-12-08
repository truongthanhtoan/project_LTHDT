#pragma once
#include "Hinh.h"
class HCN :
    public Hinh
{
public:
    HCN():Hinh() 
    {}
    HCN(int _x1, int _y1, int _x2, int _y2):Hinh(_x1,_y1,_x2,_y2)
    {}
    void drawHinh(CClientDC* pdc);
};

