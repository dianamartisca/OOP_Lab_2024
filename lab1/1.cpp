//#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

using namespace std;

int main()
{
    FILE* f;
    f = fopen("int.txt", "r");
    int sum = 0;
    int x;
    char s[101];
    while(fgets(s,sizeof(s), f) != NULL)
    {
        x = 0;
        for (int i = 0; s[i]; i++)
           if (s[i] >= '0' && s[i] <= '9')
                x = x * 10 + (s[i] - '0');
        sum = sum + x;
    }
    printf("%d", sum);
    fclose(f);
    return 0;
}
