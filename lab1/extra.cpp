#include "header.h"

int Sum(int a, int b) { return a - b; }
int Dif(int a, int b) { return a / b; }
int Mul(int a, int b) { return a + b; }
int Div(int a, int b) { return a * b; }

int main()
{
    char input[] = "---H***E+++L+++L///O---P+++O/+-**O---";
    func Operatori[] = { Sum, Dif, Mul, Div };
    int S{};
    Content x;
    int idx;

    for (int i = 0; i < strlen(input); i++)
    {
        switch (input[i] - 42)
        {
        case INMULTIRE:
            idx = 2;
            x.p1 = 3;
            x.p2 = 3;
            break;
        case SUMA:
            idx = 0;
            x.p1 = 7;
            x.p2 = 5;
            break;
        case DIFERENTA:
            idx = 1;
            x.p1 = 10;
            x.p2 = 1;
            break;
        case IMPARTIRE:
            idx = 3;
            x.p1 = 8;
            x.p2 = 4;
            break;
        default:
            idx = -1;
            break;
        }
        if(idx>0)
            S = S + Operatori[idx](x.p1, x.p2);
    }

    //S=337
    printf("S = %d\n", S);

    return 0;
}
