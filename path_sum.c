/*************************************************************************
    > File Name: path_sum.c
    > Author: wayne
    > Mail: @163.com 
    > Created Time: 2015年07月21日 星期二 15时10分20秒
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

bool path_sum(treenode root, int target)
{
    if(root == NULL)
        return false;
    int remain = target - root->val;
    if(root->left == NULL && root->right == NULL && remain == 0)
    {
        return true;
    }
    return path_sum(root->left, remain) || path_sum(root->right, remain);
}



int main()
{
    int target = 22;
    treenode root = newnode(5);

    root->left = newnode(4);
    root->right = newnode(8);
    root->left->left = newnode(11);
    root->left->left->left = newnode(7);
    root->left->left->right = newnode(2);

    root->right->right = newnode(4);
    root->right->left = newnode(13);
    root->right->right->right = newnode(1);

    printpostorder(root);
    printf("\n");
    int ret;
    ret = path_sum(root, target);
    printf("ret is %d\n", ret);
    if(ret == 1)
    {

        printf("path has the sum");
    }
    printf("\n");
    return 0;
}
