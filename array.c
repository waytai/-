/*************************************************************************
    > File Name: array.c
    > Author: wayne
    > Mail: @163.com 
    > Created Time: 2015年07月10日 星期五 11时28分22秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>


int main()
{
    int **i;
    int row = 4;
    int colum = 5;
    i = (int **)malloc(sizeof(int*)*row);
    int r;
    int c = 0;
    for(r=0; r<row; r++)
    {
        i[r]  = (int *)malloc(sizeof(int)*colum);
        for(c=0; c<colum; c++)
        {
            i[r][c] = r*c;
        }
    }

    for(r=0; r<row; r++)
    {
        for(c=0; c<colum; c++)
        {
            printf("%d  ",i[r][c] );
        }
        printf("\n");
    }


    for(r=0; r<row; r++)
    {
        free(i[r]);
    }
    free(i);
    return 0;
}
