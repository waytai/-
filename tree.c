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

int main()
{
    treenode root = newnode(1);
    root->left = newnode(2);
    root->right = newnode(3);
    root->left->left = newnode(4);
    root->left->right = newnode(5);
    printpostorder(root);
    printf("\n");
    return 0;
}



