#include "pch.h"
#include "HCN.h"

void HCN::drawHinh(CClientDC* pdc)
{
    

    // T?o pen cho vi?n
    CPen pen(PS_SOLID, 3, RGB(128, 0, 128)); // Vi?n xanh d??ng d�y 3 pixel
    CPen* oldPen = pdc->SelectObject(&pen);

    // V? h�nh ch? nh?t v?i brush v� pen m?i
    pdc->Rectangle(x1, y1, x2, y2);

    // Kh�i ph?c l?i brush v� pen c? ngay sau khi v? h�nh ch? nh?t
   
    pdc->SelectObject(oldPen);
}
