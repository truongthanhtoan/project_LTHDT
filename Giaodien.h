#pragma once
#include "HCN.h"
#include "Snake.h"
#include "Food.h"
#include <windows.h> // Th�m th? vi?n n�y ?? s? d?ng HANDLE v� c�c h�m li�n quan
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
    void displayGameOver(CClientDC* pdc); // Th�m khai b�o h�m n�y
    void resetSnake(); // Th�m khai b�o h�m n�y
    void handleKeyPress(WPARAM wParam); // Th�m khai b�o h�m n�y
};