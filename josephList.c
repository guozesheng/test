#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int num;
    struct node *next;
}NODE;

NODE *initList(int len);
void printList(NODE *p);
NODE *josephList(NODE *p, int n);

int main(int argc, const char *argv[])
{
    NODE *head;
    head = initList(2);
    printList(head);
    head = josephList(head, 1);
    
    return 0;
}

NODE *josephList(NODE *p, int n)
{
    int counter = 1;
    NODE *ptr = p;

    while (p != p->next) 
    {
        printf("%5d", p->next->num);
        if (n == counter++) 
        {
            counter = 1;
            printf("(out)\n");
            ptr = p->next;
            p->next = ptr->next;
            free(ptr);
        }
        p = p->next;
    }
    printf("The last is %d\n", p->num);
    return NULL;

}

void printList(NODE *p)
{
    NODE *ptr = p;
    if (p == NULL) 
    {
        return;
    }
    while (ptr->next != p) 
    {
        printf("%5d", ptr->next->num);
        ptr = ptr->next;
    }
    printf("%5d\n", p->num);
}

NODE *initList(int len)
{
    int i = 1;
    NODE *head, *p, *ptr;

    if ((head = malloc(sizeof(NODE))) == NULL)
    {
        return NULL;
    }
    head->num = i;
    head->next = head;
    ptr = head;

    for (i++; i <= len; i++) 
    {
        if ((p = malloc(sizeof(NODE))) == NULL)
        {
            return NULL;
        }
        p->num = i;
        p->next = head;
        ptr->next = p;
        ptr = ptr->next;
    }

    return ptr;
}
