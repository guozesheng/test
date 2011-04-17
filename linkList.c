#include <stdio.h>
#include <string.h>

typedef struct node
{
    int num;
    char name[20];
    char level;
}NODE;

int main(int argc, const char *argv[])
{
    NODE stu;
    NODE *ptr;
    ptr = &stu;

    printf("Input the number:");
    scanf("%d", &ptr->num);
    printf("Input the name:");
    scanf("%s", ptr->name);
    getchar();
    printf("Input the level:");
    scanf("%c", &ptr->level);
    printf("number: %d, name: %s, level: %c\n", ptr->num, ptr->name, ptr->level);
    
    return 0;
}
