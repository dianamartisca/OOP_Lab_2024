#include"Math.h"
#include <iostream>

int main()
{
    std::cout << Math::Add(2, 3)<<'\n';
    std::cout << Math::Add(2, 3, 5)<<'\n';
    std::cout << Math::Add(2.7, 3.8)<<'\n';
    std::cout << Math::Add(2.7, 3.8, 5.4)<<'\n';
    std::cout << Math::Mul(2, 3)<<'\n';
    std::cout << Math::Mul(2, 3, 5)<<'\n';
    std::cout << Math::Mul(2.7, 3.8)<<'\n';
    std::cout << Math::Mul(2.7, 3.8, 5.4)<<'\n';
    std::cout << Math::Add(5, 1, 2, 3, 4, 5)<<'\n';
    char* s = Math::Add("ana", " are mere");
    if (s != nullptr)
        std::cout << s;
}
