
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "tree.h"

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

// int FindHeight(struct BstNode *root)
// {
//     return;
// }
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

// Traversing the Trees
void Preorder(struct BstNode *root)
{
    if (root == NULL)
        return;
    printf("%d ", root->data);
    Preorder(root->left);
    Preorder(root->right);
}

void Inorder(struct BstNode *root)
{
    if (root == NULL)
        return;

    Preorder(root->left);
    printf("%d ", root->data);
    Preorder(root->right);
}

void Postorder(struct BstNode *root)
{
    if (root == NULL)
        return;

    Preorder(root->left);
    Preorder(root->right);
    printf("%d ", root->data);
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
    bool check = 0;
    struct BstNode *root = NULL;
    root = Insert(root, 15);
    root = Insert(root, 10);
    root = Insert(root, 20);
    root = Insert(root, 25);
    root = Insert(root, 8);
    root = Insert(root, 12);
    root = Insert(root, 55);
    root = Insert(root, 2);

    if (Search(root, 20) == true)
    {
        printf("Found!\n");
        printf("%d\n", FindMin(root));
        printf("%d\n", FindMinRecursion(root));
        printf("%d", FindMax(root));
    }
    else
    {
        printf("Not found!\n");
    }
       printf("%d ", maxDepth(root));

    Preorder(root);
    check = IsBinarySearchTree(root);
    printf("%d ", check);

    // struct BstNode *root = NULL;
    // root = Insert(root, 5);
    // root = Insert(root, 10);
    // root = Insert(root, 3);
    // root = Insert(root, 4);
    // root = Insert(root, 1);
    // root = Insert(root, 11);

    // Deleting node with value 5, change this value to test other cases
    root = Delete(root, 11);

    // Print Nodes in Inorder
    Inorder(root);
    printf("/n");
    return 0;
}