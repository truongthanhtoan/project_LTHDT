#include "pch.h"
#include "Giaodien.h"
#include <windows.h> 
#include <atlstr.h>
#include <iostream>
using namespace std;

void setcolor(int color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}

Giaodien::Giaodien()
{
    control = 0;
    score = 0;
    end = 0;
    direction = 38;
    frame = HCN(xDau, yDau, xDau + RONG, yDau + RONG);
    snake = Snake(xDau + 10 * D, yDau + 10 * D);
    food = Food(xDau + 5 * D, yDau + 10 * D, xDau + 6 * D, yDau + 11 * D);
}

void Giaodien::resetSnake()
{
    snake = Snake(xDau + 10 * D, yDau + 10 * D);
    direction = 38; // Reset direction to initial state
    end = 0; // Clear end game state
}

void Giaodien::drawHinh(CClientDC* pdc)
{
    // Tạo font chữ đậm
    CFont boldFont;
    boldFont.CreateFont(
        25,                        // Chiều cao
        10,                         // Chiều rộng
        0,                         // Escapement
        0,                         // Orientation
        FW_BOLD,                   // Độ đậm
        FALSE,                     // Italic
        FALSE,                     // Gạch chân
        0,                         // StrikeOut
        ANSI_CHARSET,              // CharSet
        OUT_DEFAULT_PRECIS,        // OutPrecision
        CLIP_DEFAULT_PRECIS,       // ClipPrecision
        DEFAULT_QUALITY,           // Chất lượng
        DEFAULT_PITCH | FF_SWISS,  // PitchAndFamily
        _T("Arial"));              // Tên font

    // Chọn font chữ đậm vào ngữ cảnh thiết bị
    CFont* pOldFont = pdc->SelectObject(&boldFont);

    // Đặt màu chữ và chế độ nền
    pdc->SetTextColor(RGB(255, 0, 0)); // Màu đỏ cho điểm số
    pdc->SetBkMode(TRANSPARENT);

    CRect scoreRect(xDau, yDau / 2, xDau + 200, yDau / 2 + 20);
    pdc->FillSolidRect(scoreRect, RGB(255, 255, 255));

    // Điểm
    CString strscore;
    strscore.Format(_T("SCORE: %d "), score);
    pdc->TextOutW(xDau, yDau / 2, strscore);

    // Thay đổi màu chữ cho hướng dẫn
    pdc->SetTextColor(RGB(165, 42, 42)); // Màu xanh cho hướng dẫn
    CString strguide;
    strguide.Format(_T("Nhan PHIM CACH de bat dau | PHIM MUI TEN de di chuyen"));
    pdc->TextOutW(xDau, yDau + RONG + 10, strguide);

    // Trong khung
    frame.drawHinh(pdc);
    snake.drawHinh(pdc);
    food.drawHinh(pdc);

    // Nếu trò chơi đã kết thúc, hiển thị thông báo kết thúc trò chơi và điểm số
    if (end == -1) {
        displayGameOver(pdc);
    }
}

void Giaodien::showMove(CClientDC* pdc)
{
    while (control == 1)
    {
        drawHinh(pdc);
        Sleep(30);
    }
}

void Giaodien::moveSnake()
{
    while (control == 1)
    {
        if (direction == 38) snake.Up();
        if (direction == 37) snake.Left();
        if (direction == 39) snake.Right();
        if (direction == 40) snake.Down();
        eatFood();
        checkFrame();
        Sleep(200);
        touchTail();
    }
}

void Giaodien::checkFrame()
{
    if (snake.head.y2 <= frame.y1) //khung trên
    {
        snake.head.y2 = frame.y2;
        snake.head.y1 = frame.y2 - D;
    }
    if (snake.head.x2 <= frame.x1) //khung trái
    {
        snake.head.x2 = frame.x2;
        snake.head.x1 = frame.x2 - D;
    }
    if (snake.head.x1 >= frame.x2) //khung phải
    {
        snake.head.x1 = frame.x1;
        snake.head.x2 = frame.x1 + D;
    }
    if (snake.head.y1 >= frame.y2) //khung dưới
    {
        snake.head.y1 = frame.y1;
        snake.head.y2 = frame.y1 + D;
    }
}

void Giaodien::startG()
{
    control = 1;
    score = 0;
    resetSnake(); // Reset the snake's state
}

int Giaodien::eatFood()
{
    int _x = (snake.head.x1 + snake.head.x2) / 2;
    int _y = (snake.head.y1 + snake.head.y2) / 2;
    if (food.checkHinh(CPoint(_x, _y)) == 1)
    {
        score++;
        snake.addTail();
        Sleep(30);
        newFood();
        return 1;
    }
    else return 0;
}

void Giaodien::newFood()
{
    int pos, r, _x, _y;
    pos = RONG / D;
    r = rand() % pos;
    _x = xDau + r * D;
    r = rand() % pos;
    _y = yDau + r * D;

    while (_x == food.x1 && _y == food.x2)
    {
        r = rand() % pos;
        _x = xDau + r * D;
        r = rand() % pos;
        _y = yDau + r * D;
    }
    food = Food(_x, _y, _x + D, _y + D);
}

void Giaodien::touchTail()
{
    if (snake.checkTouchTail() == 1)
    {
        control = 0;
        end = -1;
    }
}

void Giaodien::displayGameOver(CClientDC* pdc)
{
    // Tạo font chữ đậm cho thông báo kết thúc trò chơi
    CFont gameOverFont;
    gameOverFont.CreateFont(
        40,                        // Chiều cao
        20,                         // Chiều rộng
        0,                         // Escapement
        0,                         // Orientation
        0,                   // Độ đậm
        FALSE,                     // Italic
        FALSE,                     // Gạch chân
        0,                         // StrikeOut
        ANSI_CHARSET,              // CharSet
        OUT_DEFAULT_PRECIS,        // OutPrecision
        CLIP_DEFAULT_PRECIS,       // ClipPrecision
        DEFAULT_QUALITY,           // Chất lượng
        DEFAULT_PITCH | FF_SWISS,  // PitchAndFamily
        _T("Arial"));              // Tên font

    // Chọn font chữ kết thúc trò chơi vào ngữ cảnh thiết bị
    CFont* pOldFont = pdc->SelectObject(&gameOverFont);

    // Đặt màu chữ và chế độ nền
    pdc->SetTextColor(RGB(0, 0, 255)); // Màu xanh cho thông báo kết thúc trò chơi
    pdc->SetBkMode(TRANSPARENT);

    // Hiển thị thông báo kết thúc trò chơi
    CString strGameOver;
    strGameOver.Format(_T("END GAME"));
    pdc->TextOutW(xDau + RONG / 2, yDau + RONG / 2, strGameOver);

    // Hiển thị nút khởi động lại
    CString strRestart;
    strRestart.Format(_T("Nhan PHIM CACH de choi lai"));
    pdc->TextOutW(xDau + RONG + 50, yDau + 50, strRestart);

    // Khôi phục font chữ cũ
    pdc->SelectObject(pOldFont);
}

// Add this function to handle key presses
void Giaodien::handleKeyPress(WPARAM wParam)
{
    switch (wParam)
    {
    case VK_ESCAPE:
        exit(0); // Exit the program when ESC is pressed
        break;
    case VK_SPACE:
        if (control == 0) {
            startG(); // Start the game when SPACE is pressed
        }
        break;
    case VK_UP:
        if (direction != 40) direction = 38; // Up arrow key
        break;
    case VK_DOWN:
        if (direction != 38) direction = 40; // Down arrow key
        break;
    case VK_LEFT:
        if (direction != 39) direction = 37; // Left arrow key
        break;
    case VK_RIGHT:
        if (direction != 37) direction = 39; // Right arrow key
        break;
    }
}