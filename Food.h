#pragma once
#include "TRON.h"
class Food :
    public TRON
{
public:
    Food():TRON(){}
    Food(int _x1, int _y1, int _x2, int _y2):TRON(_x1, _y1, _x2, _y2){}
    void drawHinh(CClientDC* pdc);
};

