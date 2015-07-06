/*************************************************************************
    > File Name: sort.c
    > Author: wayne
    > Mail: @163.com 
    > Created Time: 2015年07月03日 星期五 11时31分26秒
 ************************************************************************/

#include<stdio.h>

void insert_sort(int a[], int n)
{
    int i, j, tmp;
    for(i=1;i<n;i++)
    {
        tmp = a[i];
        j = i;
        while(j>0 && a[j-1]>tmp)
        {
            a[j] = a[j-1];
            j-- ;
        }
        a[j] = tmp;
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

    insert_sort(a, len);
    print_array(a, len);
    printf("\n");
    return 0;
}
