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
NODE *delLink(NODE *head);
void printMenu(void);
int getChoice(void);

int main(int argc, const char *argv[])
{
    NODE *head = NULL;
    int i = 1;
    while (i) 
    {
        printMenu();
        switch(getChoice())
        {
            case 1:
                head = insertList(head);
                break;
            case 2:
                head = delLink(head);
                break;
            case 3:
                printList(head);
                break;
            case 0:
                //exit(0);
                i = 0;
                break;
            default:
                printf("wrong!\n");
                break;
        }
        
    }
    
    return 0;
}

int getChoice(void)
{
    int choice;
    scanf("%d", &choice);
    return choice;
}

void printMenu(void)
{
    printf("\t1.Insert list.\n");
    printf("\t2.Delete list.\n");
    printf("\t3.Print  list.\n");
    printf("\t0.Exit.\n");
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
    if (p == NULL) 
    {
        printf("This list is NULL!\n");
        return;
    }
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
    scanf("%d", &num);

    if (num == head->num) 
    {
        ptr = head;
        head = head->next;
        free(ptr);
    }
    else 
    {
        while ((p->next != NULL) && (p->next->num != num)) 
        {
            p = p->next;
        }
        if (num == p->next->num) 
        {
            ptr = p->next;
            p->next = p->next->next;
            free(ptr);
        }
        else 
        {
            printf("No match!\n");
        }
    }

    return head;
}