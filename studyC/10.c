/*
指向指针的数组, 实现字符串按序排列
*/

#include <stdio.h>
#include <string.h>

void main()
{
    void pri(char *cstr[], int n);
    void sort(char *cstr[], int n);
    
    char *cstr[]={"Changchun", "Jilin", "CCU", "China", "Lindong"};
    pri(cstr, 5);
    sort(cstr, 5);
    printf("\n\n");
    pri(cstr, 5);
}

void sort(char *cstr[], int n)
{
    int i, j, k;
    char *temp;
    for (i=0; i<n-1; i++)
    {
        for (j=i+1; j<n; j++)
        {
            if (strcmp(cstr[i] , cstr[j]) > 0)
            {
                temp = cstr[j];
                cstr[j] = cstr[i];
                cstr[i] = temp;
            }
        }
    }
}

void pri(char *cstr[], int n)
{
    while (n--)
    {
        printf("%s\n", *cstr++);
    }
}
