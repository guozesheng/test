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

    printf("Input the number:");
    scanf("%d", &ptr->num);
    printf("Input the name:");
    scanf("%s", ptr->name);
    printf("Input the score:");
    scanf("%d", &ptr->score);
    printf("number: %d, name: %s, score: %d\n", ptr->num, ptr->name, ptr->score);
    
    return 0;
}
