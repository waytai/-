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
    for(i=0;i<inordersize-1;i++)
    {
        if(key == inorder[i])
            return i;
    }

    return -1;
}


struct TreeNode *buildTree(int *inorder, int inordersize, int *postorder, int postordersize)
{
    if(inorder == NULL || postorder == NULL  || inordersize == 0|| postordersize ==0)
        return NULL;
    
    treenode root = newnode(postorder[postordersize-1]);

    int index = searchindex(inorder, inordersize, postorder[postordersize-1]);
    index = index + 1;
    printf("---- %d\n", index);
    if (index == -1)
        return NULL;
    root->left = buildTree(inorder,index, postorder,index);
    root->right = buildTree(inorder+index+1,inordersize-index-1, postorder+index, postordersize-index-1);
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
    int inorder[]  = {4,2,5,1,6,3,7};
    int postorder[] = {4,5,2,6,7,3,1};
    int inordersize= sizeof(inorder)/sizeof(int);
    int postordersize ;
    postordersize= inordersize;
    printf("%d\n", inordersize);
    treenode tree = buildTree(inorder, inordersize, postorder, postordersize);
    printpostorder(tree);
    printf("\n");
    return 0;
}



