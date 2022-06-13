

/* Data structures: Array implementation of Queue */

#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 101

struct ArrayStack
{
    int top;
    int capacity;
    int *array;
};

struct ArrayStack *CreateStack()
{
    struct ArrayStack *S = (struct ArrayStack *)malloc(sizeof(struct ArrayStack));
    int *arr = (int *)malloc(MAXSIZE * sizeof(int));

    if (S == NULL)
    {
        printf("Error:\n");
        return NULL;
    }

    S->top = -1;
    S->capacity = MAXSIZE;
    S->array = arr;
    if (S->array == NULL)
    {
        return NULL;
    }
    return S;
}

int IsEmptyStack(struct ArrayStack *S)
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

int IsFullStack(struct ArrayStack *S)
{
    return (S->top == S->capacity - 1);
}

void Push(struct ArrayStack *S, int data)
{
    if (IsFullStack(S))
    {
        printf("Stack overflow!");
    }
    else
    {
        S->top = S->top + 1;
        S->array[S->top] = data;
    }
}

void Pop(struct ArrayStack *S)
{
    if (IsEmptyStack(S))
    {
        printf("Stack is empty!");
        return;
    }
    S->top = S->top - 1;
}
void DeleteStack(struct ArrayStack *S)
{
    if (S)
    {
        if (S->array)
        {
            free(S->array);
        }
        free(S);
    }
}

int main()
{

    struct ArrayStack *S;
    S = CreateStack();
    Push(S, 10);
    Push(S, 3);
    Push(S, 25);
    Pop(S);
    Push(S, 20);

    for (int i = 0; i <= S->top; i++)
    {
        printf("%d ", S->array[i]);
    }
    DeleteStack(S);
}