/*************************************************************************
    > File Name: select_sort.c
    > Author: wayne
    > Mail: @163.com 
    > Created Time: 2015年07月06日 星期一 17时23分42秒
 ************************************************************************/
#include<stdio.h>


void select_sort(int a[],int len)
{
    int i, j, min, pos, tmp;
    for(i=0; i<len; i++)
    {
        min = a[i];
        pos = i;
        for(j=i+1;j<len;j++)
        {
            if (a[j]<min)
            {
            min = a[j];
            pos = j;
            }
        }

        printf("%d   %d\n", a[i], a[pos]);
        tmp = a[pos];
        a[pos] = a[i];
        a[i] = tmp;
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

    select_sort(a, len);
    print_array(a, len);
    printf("\n");
    return 0;
}
