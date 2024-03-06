#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<string.h>
using namespace std;

int main()
{
    char s[1001], v[50][20], * t,s1[50],s2[50];
    int k = 0;
    scanf("%[^\n]s", s);
    t = strtok(s, " ");
    while (t)
    {
        strcpy(v[k++], t);
        t = strtok(NULL, " ");
    }
    for (int i = 0; i < k - 1; i++)
        for (int j = i + 1; j < k; j++)
            if (strlen(v[i]) < strlen(v[j]))
            {
                strcpy(s1, v[i]);
                strcpy(s2, v[j]);
                strcpy(v[i], s2);
                strcpy(v[j], s1);
            }
            else
                if (strlen(v[i]) == strlen(v[j]) && strcmp(v[i], v[j]) > 0)
                {
                    strcpy(s1, v[i]);
                    strcpy(s2, v[j]);
                    strcpy(v[i], s2);
                    strcpy(v[j], s1);
                }
    for (int i = 0; i < k; i++)
        printf("%s\n", v[i]);
    return 0;
}
