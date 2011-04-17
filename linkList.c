#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int num;
    char level;
    struct node *next;
}NODE;

NODE *createLink(int n);
void printList(NODE *p);

int main(int argc, const char *argv[])
{
    NODE *head;
    head = createLink(10);
    printList(head);
    
    return 0;
}

NODE *createLink(int n)
{
    NODE *p, *head;
    int i;

    if ((head = malloc(sizeof(NODE))) == NULL)
    {
        return NULL;
    }
    head -> num = 1;
    head -> level = 'A';
    head -> next = NULL;
    p = head;

    for (i = 1; i < n; i++) 
    {
        if ((p->next = malloc(sizeof(NODE))) == NULL)
        {
            return NULL;
        }
        p -> next -> num = i + 1;
        p -> next -> level = 'A';
        p -> next -> next = NULL;
        p = p -> next;
    }

    return head;
}

void printList(NODE *p)
{
    do 
    {
        printf("num: %d\tlevel: %c\n", p->num, p->level);
        p = p->next;
    } while (p);
}
