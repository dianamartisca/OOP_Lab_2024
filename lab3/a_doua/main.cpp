#include"Canvas.h"

int main()
{
    Canvas a(30, 20);
    a.DrawCircle(10, 10, 5, '*');
    //a.FillCircle(10, 10, 5, '-');
    a.Print();
    a.Clear();

    a.DrawRect(0, 0, 15, 10,'^');
    a.FillRect(0, 0, 15, 10, '#');
    a.Print();
    a.Clear();

    a.SetPoint(3, 10, '%');
    a.DrawLine(0,0,20,20,'/');
    a.Print();
    a.Clear();
    return 0;
}
