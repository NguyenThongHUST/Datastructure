
#ifndef LinkedList_H
#define LinkedList_H

struct ListNode
{
    int data;
    struct ListNode *next;
};

int ListLength(struct ListNode *);
void PrintLinkedList(struct ListNode *);
void InsertAfter(struct ListNode *, int);
void InsertInLinkedList(struct ListNode **, int, int);
void DeleteNodeFromLinkedList(struct ListNode **, int);
#endif