/*************************************************************************
    > File Name: leetcode5.c
    > Author: wayne
    > Mail: @163.com 
    > Created Time: 2015年07月08日 星期三 10时12分11秒
    pascal's triangle
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

int **generate(int numrows, int **columnsize)
{
    int i,j;
    for(i=0; i<numrows; i++)
    {
        //*(columnsize+i)= calloc((i+1), sizeof(int));
        **(columnsize+i)= (int **)malloc((i+1)*sizeof(int));
        for(j=0; j<i+1; j++)
        {
            //(columnsize+i)[j]  = (int *)calloc((j+1), sizeof(int));
            (columnsize+i)[j]  = (int *)malloc((j+1)*sizeof(int));
            *(columnsize+i)[0] = 1;
            *(columnsize+i)[i] = 1;
            if(j>0 && j<i)
            {
            *(columnsize+i)[j] = *(columnsize+i-1)[j-1] +*(columnsize+i-1)[j];
            printf("%d\n",*(columnsize+i)[j]);
            }
        }
    }
    return columnsize;
}

void print_ab(int **ab, int len)
{
    int i,j, t;
    for(i=0; i<len; i++)
    {
        for(j=0; j<i+1; j++)
        {
            t = *(ab+i)[j];
            printf("%d\n", t);
        }
        printf("\n");

    }

    }

int main()
{
    int **ab;
    int len = 5;
    ab = generate(len, ab);
    print_ab(ab, len);
    printf("%d\n", len);
    printf("\n");
     return 0;
}

