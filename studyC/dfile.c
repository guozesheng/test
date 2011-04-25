#include <stdio.h>
#include <stdlib.h>

typedef struct node 
{
    char name[30];
    int num;

    struct node *next;
} NODE;

NODE *insert_node(NODE *head);
void save_node(NODE *head);

int main(int argc, const char *argv[])
{
    NODE *head = NULL;
    int i = 3;

    while (i--) 
    {
        head = insert_node(head);
    }

    save_node(head);
    
    return 0;
}

void save_node(NODE *head)
{
    FILE *fp;

    if ((fp = fopen("a.text", "w+")) == NULL)
    {
        perror("fopen");
        return;
    }
    while (head) 
    {
        fprintf(fp, "%s\t%d\n", head->name, head->num);
        head = head ->next;
    }

    fclose(fp);
}

NODE *insert_node(NODE *head)
{
    NODE *p;
    NODE *ptr = head;

    if ((p = malloc(sizeof(NODE))) == NULL)
    {
        perror("malloc");
        return head;
    }

    printf("Please input the name:\n");
    scanf("%s", p->name);
    getchar();
    printf("Please input the num:\n");
    scanf("%d", &p->num);
    p->next = NULL;

    if (head == NULL) 
    {
        return p;
    }
    if (ptr->num > p->num) 
    {
        p->next = ptr;
        head = p;
        return p;
    }
    while ((ptr->next != NULL) && (ptr->next->num < p->num)) 
    {
        ptr = ptr->next;
    }
    p->next = ptr->next;
    ptr->next = p;
    
    return head;
}
