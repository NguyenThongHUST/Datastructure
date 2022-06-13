

#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

void InsertInLinkedList(struct ListNode **head_ref, int data, int position)
{
    int k = 1;
    struct ListNode *newNode, *p, *q;
    newNode = (struct ListNode *)malloc(sizeof(struct ListNode));

    if (newNode == NULL)
    {
        printf("Memory error");
        return;
    }

    newNode->data = data;
    p = *head_ref;

    if (position == 1)
    {
        newNode->next = p;
        *head_ref = newNode;
    }

    else
    {
        while ((p != NULL) && (k < position))
        {
            k++;
            q = p;
            p = p->next;
        }

        q->next = newNode;
        newNode->next = p;
    }
}

void DeleteNodeFromLinkedList(struct ListNode **head_ref, int position)
{
    int k = 1;
    struct ListNode *p, *q;
    p = *head_ref;

    if (head_ref == NULL)
    {
        printf("List is empty!");
    }

    if (position == 1)
    {
        head_ref = (*head_ref)->next;
        //   free(p);
        return;
    }

    else
    {
        while ((k < position) && (p != NULL))
        {
            k++;
            q = p;
            p = p->next;
        }
        if (p == NULL)
        {
            printf("Position does not exist!");
        }
        else
        {
            q->next = p->next;
            // free(p);
        }
    }
}

void PrintLinkedList(struct ListNode *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
}

int ListLength(struct ListNode *head_ref)
{
    struct ListNode *current = head_ref;
    int count = 0;

    while (current != NULL)
    {
        count++;
        current = current->next;
    }
    return count;
}

void InsertAfter(struct ListNode *prev_node, int new_data)
{
    if (prev_node == NULL)
    {
        return;
    }

    struct ListNode *new_node = (struct ListNode *)malloc(sizeof(struct ListNode));
    new_node->data = new_data;
    new_node->next = prev_node->next;
    prev_node->next = new_node;
}

int main()
{
    struct ListNode *head_ref = (struct ListNode *)malloc(sizeof(struct ListNode));
    head_ref->data = 1;
    head_ref->next = NULL;

    InsertAfter(head_ref, 10);
    InsertAfter(head_ref->next, 20);

    InsertInLinkedList(&head_ref, 15, 3);
    DeleteNodeFromLinkedList(&head_ref, 2);
    printf("%d \n", ListLength(head_ref));
    PrintLinkedList(head_ref);
}