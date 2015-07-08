/*************************************************************************
    > File Name: leetcode5.c
    > Author: wayne
    > Mail: @163.com 
    > Created Time: 2015年07月08日 星期三 10时12分11秒
    pascal's triangle
    算法不算难，主要考察的是二位指针分配与存储
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

int **generate(int numrows, int **columnsize, int *returnsize)
{
    int i,j;
    *returnsize = numrows;
    printf("--- %d\n", *returnsize);
    printf("--- %lu\n", sizeof(int*)*(*returnsize));
    printf("--- %lu\n", sizeof(int)*(*returnsize));
    int **ans = (int **)malloc(sizeof(int*)*(*returnsize));
    (*columnsize) = (int *)malloc(sizeof(int)*(*returnsize));

    for(i=0; i<numrows; i++)
    {
        (*columnsize)[i] =  i+1;
        ans[i] = (int *)malloc(sizeof(int)*((*columnsize)[i]));
        ans[i][0] = 1;
        for(j=0; j<i; j++)
        {
            ans[i][j] = ans[i-1][j-1] + ans[i-1][j];
          }
        ans[i][i] = 1; 
        }

    return ans;
    }


int main()
{
    int returnsize = 0;
    int *columnsize = NULL;
    int **ret = generate(6, &columnsize, &returnsize);

    int i, j;
    for(i=0; i < returnsize; i++)
    {
        for(j=0; j<columnsize[i]; j++)
        {
            printf("%d ", ret[i][j]);
        }
        printf("\n");
    }
    return 0;
}

