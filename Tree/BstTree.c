
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "BstTree.h"

int Max(int a, int b)
{
    if (a >= b)
        return a;
    else
        return b;
}

/*Inserting element into BstTree*/
struct BstNode *GetNewNode(int data)
{
    struct BstNode *newnode = (struct BstNode *)malloc(sizeof(*newnode));
    newnode->data = data;
    newnode->left = newnode->right = NULL;
    return newnode;
}

struct BstNode *Insert(struct BstNode *root, int data)
{
    if (root == NULL)
    {
        root = GetNewNode(data);
    }
    else if (data <= root->data)
    {
        root->left = Insert(root->left, data);
    }
    else
    {
        root->right = Insert(root->right, data);
    }
    return root;
}

/*Searching/Finding element in BST*/

bool Search(struct BstNode *root, int data)
{
    if (root == NULL)
    {
        return false;
    }
    else if (root->data == data)
    {
        return true;
    }
    else if (data <= root->data)
    {
        return Search(root->left, data);
    }
    else
    {
        return Search(root->right, data);
    }
}

/*Finding element in BST*/
struct BstNode *Find(struct BstNode *root, int data)
{
    if (root = NULL)
        return NULL;
    while (root)
    {
        if (root->data == data)
            return root;
        else if (data > root->data)
            root = root->right;
        else
            root = root->left;
    }
    return NULL;
}

/*Find Min element in Binary tree*/

int FindMin(struct BstNode *root)
{
    if (root == NULL)
    {
        printf("Error: Tree is empty!");
        return -1;
    }

    struct BstNode *current = root;
    while (current->left != NULL)
    {
        current = current->left;
    }
    return current->data;
}

int FindMinRecursion(struct BstNode *root)
{
    if (root == NULL)
    {
        printf("Error: Tree is empty!");
        return -1;
    }
    else if (root->left == NULL)
    {
        return root->data;
    }
    return FindMinRecursion(root->left);
}

// Find min element in Binary Tree
int _FindMin(struct BstNode *root)
{
    int root_val, left, right, min;
    if (root != NULL)
    {
        root_val = root->data;
        left = _FindMin(root->left);
        right = _FindMin(root->right);
        if (left < right)
        {
            min = left;
        }
        else
            min = right;
        if (root_val < min)
            min = root_val;
    }
    return min;
}

/*Max for Binary Search Tree*/
int FindMax(struct BstNode *root)
{
    if (root == NULL)
    {
        printf("Error: Tree is empty!");
        return -1;
    }

    struct BstNode *current = root;
    while (current->right != NULL)
    {
        current = current->right;
    }
    return current->data;
}

/*Find max for Binary Tree*/
int _FindMax(struct BstNode *root)
{
    int root_val, left, right, max;
    if (root != NULL)
    {
        root_val = root->data;
        left = _FindMax(root->left);
        right = _FindMax(root->right);
        if (left > right)
        {
            max = left;
        }
        else
            max = right;
        if (root_val > max)
            max = root_val;
    }
    return max;
}

int maxDepth(struct BstNode *root)
{
    if (root == NULL)
        return -1;
    else
    {
        int lDepth = maxDepth(root->left);
        int rDepth = maxDepth(root->right);

        if (lDepth > rDepth)
            return (lDepth + 1);
        else
            return (rDepth + 1);
    }
}

int height(struct BstNode *node)
{
    if (node == NULL)
        return -1;
    return 1 + Max(height(node->left), height(node->right));
}

// Traversing the Trees
void Preorder(struct BstNode *root)
{
    if (root == NULL)
        return;
    printf("%d ", root->data);
    Preorder(root->left);
    Preorder(root->right);
}

/* Non recursive */
void PreorderNonRecursive(struct BstNode *root)
{
    struct Stack *S = CreateStack();
    while (1)
    {
        while (root)
        {
            printf("%d ", root->data);
            Push(S, root);
            root = root->left;
        }
        if (IsEmptyStack(S))
            break;
        root = Pop(S);
        root = root->right;
    }
    DeleteStack(S);
}

void Inorder(struct BstNode *root)
{
    if (root == NULL)
        return;

    Inorder(root->left);
    printf("%d ", root->data);
    Inorder(root->right);
}

void Postorder(struct BstNode *root)
{
    if (root == NULL)
        return;

    Postorder(root->left);
    Postorder(root->right);
    printf("%d ", root->data);
}

/* Level order !!! */
void LevelOrder(struct BstNode *root)
{
    struct BstNode *temp;
    struct Queue *Q = CreateQueue();
    if (!root)
        return;
    Enqueue(Q, root);
    while (!IsEmptyQueue(Q))
    {
        temp = Q->ListBstNode[Q->front];
        Dequeue(Q);
        printf("%d ", temp->data);
        if (temp->left)
        {
            Enqueue(Q, temp->left);
        }
        if (temp->right)
        {
            Enqueue(Q, temp->right);
        }
    }
    printf("\n");
}

/* Check a Binary Search Tree*/
bool IsBstUtil(struct BstNode *root, int minValue, int maxValue)
{
    if (root == NULL)
        return true;
    if ((root->data >= minValue) && (root->data < maxValue) &&
        (IsBstUtil(root->left, minValue, root->data)) &&
        (IsBstUtil(root->right, root->data, maxValue)))
    {
        return true;
    }
    else
        return false;
}

bool IsBinarySearchTree(struct BstNode *root)
{
    return IsBstUtil(root, INT_MIN, INT_MAX);
}

// Function to search a Delete a value from tree.
struct BstNode *Delete(struct BstNode *root, int data)
{
    if (root == NULL)
        return root;
    else if (data < root->data)
        root->left = Delete(root->left, data);
    else if (data > root->data)
        root->right = Delete(root->right, data);
    // Wohoo... I found you, Get ready to be deleted
    else
    {
        // Case 1:  No child
        if (root->left == NULL && root->right == NULL)
        {
            free(root);
            root = NULL;
        }
        // Case 2: One child
        else if (root->left == NULL)
        {
            struct Node *temp = root;
            root = root->right;
            free(temp);
        }
        else if (root->right == NULL)
        {
            struct Node *temp = root;
            root = root->left;
            free(temp);
        }
        // case 3: 2 children
        else
        {
            struct BstNode *temp = FindMin(root->right);
            root->data = temp->data;
            root->right = Delete(root->right, temp->data);
        }
    }
    return root;
}

int main()
{
    struct BstNode *root = NULL; // set NULL is really really important
    root = Insert(root, 5);
    root = Insert(root, 10);
    root = Insert(root, 3);
    root = Insert(root, 4);
    root = Insert(root, 1);
    root = Insert(root, 11);
    root = Delete(root, 20);

    /* Tree sorting*/
    // Inorder(root);
    if (Search(root, 11))
        printf("Found!");
    Preorder(root);
    return 0;
}
