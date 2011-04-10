/*
	冒泡法排序
*/

#include <stdio.h>

void main()
{
    //int a[10] = {9,6,5,8,7,5,1,6,8,4};
    int a[10];
    int i, j, temp;
//*
    printf("请输入10个数字：");    
    for (i=0; i<10; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("\n");
 //*/   
    for (i=0; i<10; i++)
    {
        for (j=0; j < 9-i; j++)
        {
            if (a[j] > a[j+1])
            {
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
    
    printf("正确序列为：\n");
    for (i=0; i<10; i++)
    {
        printf("%d,", a[i]);
    }
    printf("\n");
}
