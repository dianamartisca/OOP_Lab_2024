#include<iostream>

float operator"" _Kelvin(const char* x)
{
    int y;
    y=atoi(x);
    return (y - 273.15);
}

float operator"" _Fahrenheit(const char* x)
{
    int y;
    y = atoi(x);
    return (float)(y - 32) / 1.8;
}

int main() {
    float a = 300_Kelvin;
    float b = 120_Fahrenheit;
    std::cout << a << ' ' << b;
    return 0;
}

