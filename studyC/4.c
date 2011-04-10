/*
	选择法排序
*/

#include <stdio.h>

void main()
{
    int a[10] = {9,6,5,8,7,5,1,6,8,4};
    //int a[10];
    int i, j, temp;

/*    
    printf("请输入10个数字：");
    for (i=0; i<10; i++)
        scanf("%d", &a[i]);
    printf("\n");
//*/    

    for (i=0; i<9; i++)
    {
        for (j=i+1; j<10; j++)
        {
            if (a[i] > a[j])
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
    
    printf("正确的顺序是：\n");
    for (i=0; i<10; i++)
    {
        printf("%4d", a[i]);
    }
    printf("\n");
}
