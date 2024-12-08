#pragma once
#include "HCN.h"
#include "Snake.h"
#include "Food.h"
#include <windows.h> // Thêm th? vi?n này ?? s? d?ng HANDLE và các hàm liên quan
#define xDau 50
#define yDau 50
#define RONG 500


class Giaodien
{
public:
    int control, score;
    int direction;
    HCN frame;
    Snake snake;
    Food food;
    int end;
    Giaodien();
    void drawHinh(CClientDC* pdc);
    void showMove(CClientDC* pdc);
    void moveSnake();
    void checkFrame();
    void startG();
    int eatFood();
    void newFood();
    void touchTail();
    void displayGameOver(CClientDC* pdc); // Thêm khai báo hàm này
    void resetSnake(); // Thêm khai báo hàm này
    void handleKeyPress(WPARAM wParam); // Thêm khai báo hàm này
};