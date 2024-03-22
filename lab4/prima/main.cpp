#include "Sort.h"
#include <iostream>

int main()
{
    Sort a1(5, 10, 30);
    a1.Print();
    a1.InsertSort(true);
    a1.Print();
    std::cout << '\n';

    Sort a2;
    a2.Print();
    a2.QuickSort(0, a2.GetElementsCount());
    std::cout << a2.GetElementFromIndex(9) << '\n';
    a2.Print();
    std::cout << '\n';

    int v[] = { 4,6,3,7 };
    Sort a3(v, 4);
    a3.Print();
    a3.BubbleSort(true);
    a3.Print();
    std::cout << '\n';

    Sort a4(7, 5, 3, 8, 10, 3, 7, 2);
    a4.Print();
    a4.QuickSort(0, a4.GetElementsCount(),false);
    a4.Print();
    std::cout << '\n';

    char s[] = "30,2,6,77";
    Sort a5(s);
    a5.Print();
    std::cout << a5.GetElementsCount() << '\n';
    a5.BubbleSort(true);
    a5.Print();
}
