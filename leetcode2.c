/*************************************************************************
    > File Name: leetcode2.c
    > Author: wayne
    > Mail: @163.com 
    > Created Time: 2015年07月07日 星期二 16时49分58秒
    给定一个已经排序好的数组，移除重复的元素，使得新的数组只出现唯一的元素, 返回新的
    数组的长度
 ************************************************************************/

#include<stdio.h>
int removeDuplicates(int a[], int len)
{
    int i,j = 0;
    if(0 == len)
        return 0;
    for(i = 1; i< len ; i++)
    {
        if(a[j] != a[i])
            a[++j] = a[i];
    }
    return j+1;
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
    printf("%d\n", len);
    int len_remove;
    len_remove =  removeDuplicates(a, len);
    printf("%d\n", len_remove);
    print_array(a, len_remove);
    printf("\n");

    return 0;
}
