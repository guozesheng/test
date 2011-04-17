#include <stdio.h>
#include <string.h>

typedef struct node
{
    int num;
    char name[20];
    int score;
}NODE;

int main(int argc, const char *argv[])
{
    NODE stu;
    NODE *ptr;

    ptr = &stu;
    ptr->num = 15;
    strcpy(ptr->name, "XiaoGuoguo");
    printf("number: %d, name: %s\n", ptr->num, ptr->name);
    
    return 0;
}
