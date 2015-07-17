/*************************************************************************
    > File Name: same_tree.c
    > Author: wayne
    > Mail: @163.com 
    > Created Time: 2015年07月15日 星期三 16时07分37秒
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
    printpostorder(node->left);
    printf("%d ", node->val);
    printpostorder(node->right);
}


int same_tree(treenode a, treenode b)
{
    if(a==NULL && b==NULL)
    {
        return 1;
    }
    else 
    {
        if(a->val== b->val)
        {
            return same_tree(a->left, b->left)&&same_tree(a->right, b->right);
        }
        return 0;
    }
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
    treenode same_root = newnode(1);
    same_root->left = newnode(2);
    same_root->right = newnode(3);
    same_root->left->left = newnode(4);
    same_root->left->right = newnode(5);
    printpostorder(same_root);
    printf("\n");

    int same = same_tree(root, same_root);
    printf("%d\n", same);
    return 0;
}


