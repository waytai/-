/*************************************************************************
    > File Name: min_depth_btree.c
    > Author: wayne
    > Mail: @163.com 
    > Created Time: 2015年07月21日 星期二 11时20分41秒
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


int max_depth_tree(treenode node)
{
    int num = 0;
    if(!node)
    {
        return 0;
    }
    else
    {
        num = traval(node);
        return num;
    }
}


int traval(treenode node)
{
    int left_top =0, right_top = 0;
    if(!node->left && !node->right)
    {
        return 1;
    }
    if(node->right)
    {
        left_top = traval(node->right)+1;
    }
    if(node->left)
    {
        right_top = traval(node->left)+1;
    }
    return (left_top > right_top)?right_top:left_top;
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
    printf("%d\n", traval(root));
    return 0;
}
