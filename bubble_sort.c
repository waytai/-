/*************************************************************************
    > File Name: bubble_sort.c
    > Author: wayne
    > Mail: @163.com 
    > Created Time: 2015年07月06日 星期一 13时09分34秒
 ************************************************************************/

#include<stdio.h>


void bubble_sort(int a[],int len)
{
    int i, j, tmp;
    for(i=0; i<len; i++)
    {
        for(j=i; j<len; j++)
            if(a[i] > a[j])
            {
                tmp =  a[i];
                a[i] = a[j];
                a[j] = tmp;
            }
    }
}

void print_array(int a[], int n)
{
    int i;
    for(i =0 ; i<n ;i++)
    {
        printf("%d  ", a[i]);
    }
}

int main()
{
    int a[] = {3,1,5,7,2,4,6,9,20};
    int len;
    len = sizeof(a)/sizeof(int);
    printf("%d\n", len);
    print_array(a, len);
    printf("\n");

    bubble_sort(a, len);
    print_array(a, len);
    printf("\n");
    return 0;
}
