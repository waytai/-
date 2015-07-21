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


int max_sum(treenode node, int target)
{
    if(!node)
    {
        return 0;
    }
    else
    {
     return  travel_sum(node, target);
    }
}

int travel_sum(treenode node, int target)
{
    if(!node->left && !node->right)
    {
        printf("target is %d\n", target);
        printf("val is %d\n", node->val);
        if(node->val == target)
            return 1;
        else
            return 0;
    }

    target = target - node->val;
    if(node->left)
    {
        printf("left target is %d\n", target);
        travel_sum(node->left, target);
    }
    if(node->right)
    {
        printf("right target is %d\n", target);
        travel_sum(node->right, target);
    }
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
    ret = max_sum(root, target);
    printf("ret is %d\n", ret);
    if(ret == 1)
    {

        printf("path has the sum");
    }
    printf("\n");
    return 0;
}
