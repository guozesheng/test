/*
空结构体有多大
*/

#include <stdio.h>

void main()
{
    struct student
    {}stu;
    printf("%d\n", sizeof(stu));
}

/*
在 Visual C++ 6.0 下测试结果为1,在此Linux下测试，结果为0
*/
