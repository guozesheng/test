#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct node {
    int num;
    struct node *next;
}NODE;

NODE *initList(int len);
void printList(NODE *head);
NODE *checkList(NODE *head);

int main(int argc, const char *argv[])
{
    NODE *head;
    head = initList(20);
    printList(head);
    head = checkList(head);
    printList(head);

    return 0;
}

NODE *checkList(NODE *head)
{
    NODE *p = head;
    NODE *ptr, *ptmp;

    while (p->next != NULL) 
    {
        ptr = p->next;
        while (ptr->next != NULL)
        {
            if (ptr->next->num == p->num) 
            {
                ptmp = ptr->next;
                ptr->next = ptmp->next;
                free(ptmp);
            }
            else
            {
                ptr = ptr->next;
            }
        }
        p = p->next;
    }

    return head;
}

NODE *initList(int len)
{
    NODE *p, *ptr, *head;

    srand(time(NULL));
    if ((head = malloc(sizeof(NODE))) == NULL)
    {
        return NULL;
    }
    head->num = rand() % 15;
    ptr = head;

    while (len--) 
    {
        if ((p = malloc(sizeof(NODE))) == NULL)
        {
            return NULL;
        }
        p->num = rand() % 15;
        ptr->next = p;
        ptr = ptr->next;
    }
    ptr->next = NULL;
    return head;
}

void printList(NODE *head)
{
    if (head == NULL) 
    {
        printf("The list is NULL\n");
        return;
    }
    do 
    {
        printf("%3d", head->num);
        head = head->next;
    } while (head);
    printf("\n");
}
