
#include <stdio.h>
#include <stdlib.h>

/* Stack : LIFO*/
struct ListNode
{
    int data;
    struct ListNode *next;
};

/* global top*/
struct ListNode *top = NULL;

void Push(int x)
{
    struct ListNode *temp = (struct ListNode *)malloc(sizeof(*temp));
    if (temp == NULL)
    {
        printf("Error memory allocation!\n");
        return;
    }
    temp->data = x;
    temp->next = top;
    top = temp;
}

void _Push(struct ListNode **top, int x)
{
    struct ListNode *temp = (struct ListNode *)malloc(sizeof(*temp));
    if (temp == NULL)
    {
        printf("Error memory allocation!\n");
        return;
    }
    temp->data = x;
    temp->next = (*top);
    (*top) = temp;
}

void Pop()
{
    struct ListNode *temp;
    if (top == NULL)
    {
        return;
    }
    temp = top;
    top = top->next;
    free(temp);
}

void _Pop(struct ListNode **top)
{
    struct ListNode *temp;
    if ((*top) == NULL)
    {
        return;
    }
    temp = *top;
    (*top) = (*top)->next;
    free(temp);
}

void Print(struct ListNode *top)
{
    if (top == NULL)
        return;
    while (top != NULL)
    {
        printf("%d ", top->data);
        top = top->next;
    }
}

int IsEmptyStack(struct ListNode *top)
{
    if (top == NULL)
    {
        return 1;
    }
    return 0;
}

int main()
{
    struct ListNode *top = (struct ListNode *)malloc(sizeof(*top));
    top = NULL; /*realy important*/

    _Push(&top, 2);
    _Push(&top, 10);
    _Pop(&top);
    Print(top);
    free(top);
    return 0;
}