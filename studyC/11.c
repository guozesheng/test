/*
指向结构体数组的指针
*/

#include <stdio.h>

struct student
{
    int id;
    char name[20];
    char sex;
    int age;
};

struct student stu[3] = {{15, "XiaoGuo", 'F', 22}, {16, "Wang", 'F', 23}, {17, "Sun", 'F', 23}};

void main()
{
    struct student *p;
    for (p=stu; p<stu+3; p++)
    {
        printf("%d\t%s\t%c\t%d\n", p->id, p->name, p->sex, p->age);
    }
}

/*
注意：
    p=stu
    (*p).成员名
    p->成员名
    结构体变量.成员名
*/
