/*************************************************************************
    > File Name: quick_sort.c
    > Author: wayne
    > Mail: @163.com 
    > Created Time: 2015年07月07日 星期二 10时05分00秒
    思想:
    1,在数组中找到一个基准
    2.分区操作，小于基准的移到左边，大于基准的移到右边
    3.递归实现步骤2
 ************************************************************************/

#include<stdio.h>

void swap(int *a , int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}


void quick_sort(int a[],int low, int high)
{
    int i;
    i = patition(a, low-1, high);
    if(low < high)
    {
    quick_sort(a, low, i-1);
    quick_sort(a, i, high-1);
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

int patition(int a[], int p, int q)
{
    int i;
    int j = p -1 ;
    int pivot = a[q-1];
    for(i=p; i<q; i++)
    {
        if(a[i] <= pivot)
        {
            ++j;
            swap(&a[i], &a[j]);
        }
    }
    swap(&a[j], &pivot);
    return j+1;
}


int main()
{
    int a[] = {3,1,5,7,2,4,6,9,20};
    int len;
    len = sizeof(a)/sizeof(int);
    printf("%d\n", len);
    print_array(a, len);
    printf("\n");

    quick_sort(a, 0, len);
    print_array(a, len);
    printf("\n");
    return 0;
}
