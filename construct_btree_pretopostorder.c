/*************************************************************************
    > File Name: construct_btree_intopostoder.c
    > Author: wayne
    > Mail: @163.com 
    > Created Time: 2015年07月21日 星期二 17时42分01秒
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
    node->val = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}


int searchindex(int inorder[], int inordersize, int key)
{
    int i;
    for(i=0;i<inordersize;i++)
    {
        if(key == inorder[i])
            return i;
    }

    return -1;
}


struct TreeNode *buildTree(int *preorder, int preordersize, int *inorder, int inordersize)
{
    if(preorder == NULL || inorder == NULL  || preordersize == 0|| inordersize==0)
        return NULL;
    treenode root = newnode(preorder[0]);
    int index = searchindex(inorder, inordersize, preorder[0]);
    if(index == -1)
        return NULL;
    root->left = buildTree(preorder+1, index, inorder, index);
    root->right = buildTree(preorder+index+1, preordersize-index-1, inorder+index+1, inordersize-index-1);
    return root;
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
    int preorder[]  = {1,2,4,5,3,6,7};
    int inorder[] = {4,2,5,1,6,3,7};
    int preordersize = sizeof(inorder)/sizeof(int);
    int inordersize;
    inordersize = preordersize;
    printf("%d\n", preordersize);
    treenode tree = buildTree(preorder, preordersize , inorder, inordersize);
    printpostorder(tree);
    printf("\n");
    return 0;
}



