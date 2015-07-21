/*************************************************************************
    > File Name: tree.c
    > Author: wayne
    > Mail: @163.com 
    > Created Time: 2015年07月13日 星期一 16时10分16秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct TreeNode *treenode;
struct TreeNode
{
    int val;
    treenode left;
    treenode right;
};


treenode newnode(int data)
{
    treenode node = (treenode)malloc(sizeof(struct TreeNode));
    //struct TreeNode *node = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    node->val = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void printpostorder(treenode node)
{
    if(node == NULL)
    {
        return;
    }
    printpostorder(node->left);
    printpostorder(node->right);
    printf("%d ", node->val);
}

void printmidorder(treenode node)
{
    if(node == NULL)
    {
        return;
    }
    printmidorder(node->left);
    printf("%d ", node->val);
    printmidorder(node->right);
}

int getleafcount(treenode node)
{
    if(node == NULL)
    {
        return 0;
    }
    if(node->left == NULL && node->right == NULL)
    {
        return 1;
    }

    return getleafcount(node->left) + getleafcount(node->right);
}


void printpredorder(treenode node)
{
    if(node == NULL)
    {
        return;
    }
    printf("%d ", node->val);
    printpredorder(node->left);
    printpredorder(node->right);
}

int main()
{
    treenode root = newnode(1);
    root->left = newnode(2);
    root->right = newnode(3);
    root->left->left = newnode(4);
    root->left->right = newnode(5);
    printpostorder(root);
    printf("\n");
    printmidorder(root);
    printf("\n");
    printpredorder(root);
    printf("\n");
    printf("%d  ", getleafcount(root));
    printf("\n");
    return 0;
}



