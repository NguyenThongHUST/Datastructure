
#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
    int data;
    struct ListNode *next;
};

struct ListNode *front = NULL;
struct ListNode *rear = NULL;

struct Queue
{
    struct ListNode *front;
    struct ListNode *rear;
};

struct Queue *CreateQueue()
{
    struct Queue *Q;
    Q = (struct Queue *)malloc(sizeof(struct Queue));
    if (Q == NULL)
    {
        return NULL;
    }
    Q->front = Q->rear = NULL;
    return Q;
}

int IsEmptyQueue(struct Queue *Q)
{
    if (Q->front == NULL)
        return 0;
    else
        return 1;
}

void Enqueue(struct Queue *Q, int x)
{
    struct ListNode *temp = (struct ListNode *)malloc(sizeof(*temp));
    if (temp == NULL)
        return;
    temp->data = x;
    temp->next = NULL;

    if ((Q->front == NULL) && (Q->rear == NULL))
    {
        Q->front = Q->rear = temp;
        return;
    }
    Q->rear->next = temp;
    Q->rear = temp;
}

void Dequeue(struct Queue *Q)
{
    if (Q->front == NULL)
    {
        printf("Queue is Empty\n");
        return;
    }

    if (Q->front == Q->rear)
    {
        Q->front = Q->rear = NULL;
    }
    else
    {
        struct ListNode *temp = (struct ListNode *)malloc(sizeof(*temp));
        temp = Q->front;
        Q->front = temp->next;
        free(temp);
    }
}

/* Print Queue!*/
void Print(struct Queue *Q)
{
    struct Queue temp;
    temp = (*Q);
    while (temp.front != NULL)
    {
        printf("%d ", temp.front->data);
        temp.front = temp.front->next;
    }
}

void DeleteQueue(struct Queue *Q)
{
    free(Q->front);
    free(Q->rear);
    free(Q);
}

int main()
{
    struct Queue *Q;
    Q = CreateQueue();
    Enqueue(Q, 2);
    Enqueue(Q, 10);
    Enqueue(Q, 20);
    Print(Q);
    /*Print Head to Tail*/
    Dequeue(Q);
    printf("\n");
    Print(Q);
    free(Q->front);
    free(Q->rear);
    free(Q);
}