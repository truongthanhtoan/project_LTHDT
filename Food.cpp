#include "pch.h"
#include "Food.h"



void Food::drawHinh(CClientDC* pdc) {
    // T?o m?t ??i t??ng CBrush m?i v?i màu s?c mong mu?n (ví d?: màu xanh lá cây)
    CBrush newBrush(RGB(0, 255, 0)); // Màu xanh lá cây
    CBrush* oldBrush = pdc->SelectObject(&newBrush);

    // T?o m?t ??i t??ng CPen m?i cho vi?n (ví d?: màu ??)
    CPen newPen(PS_SOLID, 3, RGB(0, 0, 0)); // Vi?n ?? dày 2 pixel
    CPen* oldPen = pdc->SelectObject(&newPen);

    // G?i hàm drawHinh c?a l?p TRON ?? v? hình th?c ?n
    TRON::drawHinh(pdc);

    // Khôi ph?c l?i ??i t??ng brush và pen c?
    pdc->SelectObject(oldBrush);
    pdc->SelectObject(oldPen);
}
