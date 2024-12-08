#include "pch.h"
#include "HCN.h"

void HCN::drawHinh(CClientDC* pdc)
{
    

    // T?o pen cho vi?n
    CPen pen(PS_SOLID, 3, RGB(128, 0, 128)); // Vi?n xanh d??ng dày 3 pixel
    CPen* oldPen = pdc->SelectObject(&pen);

    // V? hình ch? nh?t v?i brush và pen m?i
    pdc->Rectangle(x1, y1, x2, y2);

    // Khôi ph?c l?i brush và pen c? ngay sau khi v? hình ch? nh?t
   
    pdc->SelectObject(oldPen);
}
