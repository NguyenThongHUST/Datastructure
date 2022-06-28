
#ifndef BSTTREE_H
#define BSTTREE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAXSIZE 101

int Max(int, int);

struct BstNode
{
    int data;
    struct BstNode *left;
    struct BstNode *right;
};

struct Queue
{
    int front;
    int rear;
    struct BstNode *ListBstNode[MAXSIZE];
};

struct Stack
{
    int top;
    int capacity;
    struct BstNode *ListBstNode[MAXSIZE];
};

struct Queue *CreateQueue();
bool IsEmptyQueue(struct Queue *);
bool IsFullQueue(struct Queue *);
void Enqueue(struct Queue *, struct BstNode *);
void Dequeue(struct Queue *);
void Print(struct Queue *);

struct BstNode *GetNewNode(int);
struct BstNode *Insert(struct BstNode *, int);
bool Search(struct BstNode *, int);
int FindMax(struct BstNode *);
void Preorder(struct BstNode *);
bool IsBinarySearchTree(struct BstNode *);
bool IsBstUtil(struct BstNode *, int, int);
bool IsBinarySearchTree(struct BstNode *);
struct BstNode *Delete(struct BstNode *, int);

/*Queue library*/
struct Queue *CreateQueue()
{
    struct Queue *Q;
    Q = (struct Queue *)malloc(sizeof(*Q));
    if (Q == NULL)
    {
        printf("Memory Error!\n");
        return;
    }
    Q->front = -1;
    Q->rear = -1;
    return Q;
}

bool IsEmptyQueue(struct Queue *Q)
{
    if ((Q->front == -1) && (Q->rear == -1))
    {
        return true;
    }
    else
        return false;
}

bool IsFullQueue(struct Queue *Q)
{
    if ((Q->rear + 1) % MAXSIZE == Q->front)
    {
        return true;
    }
    else
        return false;
}

void Enqueue(struct Queue *Q, struct BstNode *node)
{
    if (IsFullQueue(Q))
    {
        printf("Queue is full!\n");
        return;
    }
    if (IsEmptyQueue(Q))
    {
        Q->front = 0;
        Q->rear = 0;
    }
    else
    {
        Q->rear = (Q->rear + 1) % MAXSIZE;
    }
    Q->ListBstNode[Q->rear] = node;
}

void Dequeue(struct Queue *Q)
{
    if (IsEmptyQueue(Q))
        return;
    else if (Q->front == Q->rear)
    {
        Q->rear = Q->front = -1;
    }
    else
    {
        int temp = Q->front;
        Q->front = (Q->front + 1) % MAXSIZE;
    }
}

void DeleteQueue(struct Queue *Q)
{
    free(Q);
}

void Print(struct Queue *Q)
{
    int count = (Q->rear + MAXSIZE - Q->front) % MAXSIZE + 1;
    for (int i = 0; i < count; i++)
    {
        printf("%d ", Q->ListBstNode[i]->data);
    }
    printf("\n");
}

/*Stack library*/
struct Stack *CreateStack()
{
    struct Stack *S = (struct Stack *)(malloc(sizeof(*S)));
    struct BstNode *temp = (struct BstNode *)malloc(MAXSIZE * sizeof(struct BstNode));
    if (S == NULL)
    {
        printf("Error:\n");
        return NULL;
    }

    S->top = -1;
    S->capacity = MAXSIZE;
    S->ListBstNode[0] = temp;

    if (S->ListBstNode == NULL)
    {
        return NULL;
    }
    return S;
}

int IsEmptyStack(struct Stack *S)
{
    if (S->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int IsFullStack(struct Stack *S)
{
    return (S->top == S->capacity - 1);
}

void Push(struct Stack *S, struct BstNode *node)
{
    if (IsFullStack(S))
    {
        printf("Stack overflow!\n");
        return;
    }
    else
    {
        S->top = S->top + 1;
        S->ListBstNode[S->top] = node;
    }
}

struct BstNode *Pop(struct Stack *S)
{
    if (IsEmptyStack(S))
    {
        printf("Stack is empty!\n");
        return;
    }
    struct BstNode *temp;
    temp = S->ListBstNode[S->top];
    S->top = S->top - 1;
    return temp;
}

void DeleteStack(struct Stack *S)
{
    if (S)
    {
        if (S->ListBstNode)
        {
            free(S->ListBstNode);
        }
        free(S);
    }
}
#endif