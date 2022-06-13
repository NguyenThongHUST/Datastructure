
#ifndef TREE_H
#define TREE_H

#include <stdio.h>
#include <stdlib.h>

struct BstNode
{
    int data;
    struct BstNode *left;
    struct BstNode *right;
};

struct BstNode *GetNewNode(int);
struct BstNode *Insert(struct BstNode *, int);
bool Search(struct BstNode *, int);
int FindMax(struct BstNode *);
void Preorder(struct BstNode *);
bool IsBinarySearchTree(struct BstNode *);
bool IsBstUtil(struct BstNode *, int, int);
bool IsBinarySearchTree(struct BstNode *);
struct BstNode *Delete(struct BstNode *, int);
#endif