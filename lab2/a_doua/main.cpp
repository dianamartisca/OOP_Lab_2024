#include"Student.h"
#include"GlobalFunctions.h"
#include <iostream>

int main()
{
    Student a, b;
    a.SetNume("Ionescu Gica");
    b.SetNume("Moraru Ioana");
    std::cout << a.GetNume() << '\n' << b.GetNume() << '\n' << compNume(a, b) << '\n' << '\n';
    a.SetMate(5.5);
    b.SetMate(8);
    std::cout << a.GetMate() << '\n' << b.GetMate() << '\n' << compMate(a, b) << '\n' << '\n';
    a.SetEng(7.9);
    b.SetEng(10);
    std::cout << a.GetEng() << '\n' << b.GetEng() << '\n' << compEng(a, b) << '\n' << '\n';
    a.SetIst(7.4);
    b.SetIst(6.8);
    std::cout << a.GetIst() << '\n' << b.GetIst() << '\n' << compIst(a, b) << '\n' << '\n';
    std::cout << a.GetAvg() << '\n' << b.GetAvg() << '\n' << compAvg(a, b) << '\n';
}
