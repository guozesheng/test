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
NODE *insertList(NODE *head);

int main(int argc, const char *argv[])
{
    NODE *head = NULL;
    int i = 5;
    //head = createLink(10);
    //printList(head);
    while (i--) 
    {
        printf("%d:", i);
        head = insertList(head);
    }
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
        p -> next -> num = i * 2;
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

NODE *insertList(NODE *head)
{
    NODE *p;
    NODE *ptr = head;

    if ((p = malloc(sizeof(NODE))) == NULL)
    {
        return NULL;
    }
    printf("Input the number:");
    scanf("%d", &p->num);
    printf("Input the level:");
    getchar();
    scanf("%c", &p->level);
    p->next = NULL;

    if (head == NULL) 
    {
        return p;
    }
    if (p->num < ptr->num) 
    {
        p->next = ptr;
        head = p;
        return head;
    }

    while ((ptr->next != NULL) && (ptr->next->num < p->num)) 
    {
        ptr = ptr->next;
    }
    p->next = ptr->next;
    ptr->next = p;

    return head;
}

NODE *delLink(NODE *head)
{
    int num;
    NODE *p = head;
    NODE *ptr;

    if (head == NULL) 
    {
        printf("Empty link!\n");
        return NULL;
    }
    printf("Input the number to delete:\n");
    scnaf("%d", &num);

    if (num == head->num) 
    {
        ptr = head;
        head = head->next;
        free(ptr);
        return head;
    }

    while ((p->next != NULL) && (p->next->num != num)) 
    {
        p = p->next;
    }
    if (num == p->next-num) 
    {
        ptr = p->next;
        p->next = p->next->next;
        free(ptr);
    }

    return head;
}
