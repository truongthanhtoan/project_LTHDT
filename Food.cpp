#include "pch.h"
#include "Food.h"



void Food::drawHinh(CClientDC* pdc) {
    // T?o m?t ??i t??ng CBrush m?i v?i m�u s?c mong mu?n (v� d?: m�u xanh l� c�y)
    CBrush newBrush(RGB(0, 255, 0)); // M�u xanh l� c�y
    CBrush* oldBrush = pdc->SelectObject(&newBrush);

    // T?o m?t ??i t??ng CPen m?i cho vi?n (v� d?: m�u ??)
    CPen newPen(PS_SOLID, 3, RGB(0, 0, 0)); // Vi?n ?? d�y 2 pixel
    CPen* oldPen = pdc->SelectObject(&newPen);

    // G?i h�m drawHinh c?a l?p TRON ?? v? h�nh th?c ?n
    TRON::drawHinh(pdc);

    // Kh�i ph?c l?i ??i t??ng brush v� pen c?
    pdc->SelectObject(oldBrush);
    pdc->SelectObject(oldPen);
}
