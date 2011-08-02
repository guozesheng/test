#include <stdio.h>
#include <stdlib.h>

typedef struct stu
{
    int id;
    int num;
    struct stu *next;
} NODE_stu;

NODE_stu *queue_insert(NODE_stu *head);
int queue_print(NODE_stu *head);
NODE_stu *qinput(NODE_stu *p);
NODE_stu *queue_delete(NODE_stu *head, NODE_stu *qnode);

int main(int argc, const char *argv[])
{
    NODE_stu *head = NULL;

    head = queue_insert(head);
    head = queue_insert(head);
    head = queue_insert(head);

    queue_print(head);
    head = queue_delete(head, head->next);
    printf("\n");
    queue_print(head);
    
    return 0;
}

NODE_stu *queue_insert(NODE_stu *head)
{
    NODE_stu *p; 
    NODE_stu *ptr = NULL;

    p = head;

    if (p == NULL) 
    {
        p = qinput(ptr);
        return p;
    }

    while (p->next != NULL) 
    {
        p = p->next;
    }

    p->next = qinput(ptr);
    
    return head;
}

NODE_stu *queue_delete(NODE_stu *head, NODE_stu *qnode)
{
    NODE_stu *p = head;

    if (p == NULL) 
    {
        return NULL;
    }
    else if (p == qnode) 
    {
        free(qnode);
        return NULL;
    }

    while (p->next != qnode && p != NULL) 
    {
        p = p->next;
    }
    p->next = qnode->next;
    free(qnode);
    
    return head;
}

NODE_stu *qinput(NODE_stu *p)
{
    NODE_stu *ptr;
    
    ptr = (NODE_stu *)malloc(sizeof(NODE_stu));
    if (ptr == NULL) 
    {
        perror("malloc");
        exit(1);
    }
    printf("Please input the id:");
    scanf("%d", &ptr->id);
    printf("Please input the num:");
    scanf("%d", &ptr->num);
    ptr->next = NULL;

    p = ptr;
    return p;
}

int queue_print(NODE_stu *head)
{
    NODE_stu *p = head;

    while (p != NULL) 
    {
        printf("id:%d\t", p->id);
        printf("num:%d\n", p->num);
        p = p->next;
    }
    
    return 0;
}
