/*************************************************************************
    > File Name: leetcode1.c
    > Author: wayne
    > Mail: @163.com 
    > Created Time: 2015年07月07日 星期二 16时26分45秒
    题目：在一个数组里面移除指定value，并返回新的数组长度
 ************************************************************************/

#include<stdio.h>


int removeElement(int a[], int len, int elem)
{
    int i, j=0;
    for(i=0; i < len ; i++)
    {
        if(a[i] == elem)
        {
            continue;
        }
        a[j] = a[i];
        j++;
    }
    return j;
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
    int a[] = {3,1,1,5,7,2,4,6,9,20};
    int len = sizeof(a)/sizeof(int);
    int len_remove;
    len_remove =  removeElement(a, len, 1);
    printf("%d\n", len_remove);
    print_array(a, len_remove);
    printf("\n");
    return 0;
}

