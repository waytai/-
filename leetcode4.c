/*************************************************************************
    > File Name: leetcode4.c
    > Author: wayne
    > Mail: @163.com 
    > Created Time: 2015年07月07日 星期二 17时26分16秒
    Plus One    
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

void print_array(int a[], int n)
{
    int i;
    for(i =0 ; i<n ;i++)
    {
        printf("%d  ", a[i]);
    }
}

int *PlusOne(int digits[], int len)
{
    int i, *res;
    res = (int *)malloc(sizeof(int)*len);
    int sum = 0;
    int one = 1;
    for(i=len-1; i>=0; i--)
    {
        sum = one + digits[i];
        printf("sum is %d\n", sum);
        one = sum/10;
        res[i] = sum%10;
    }

    if(one > 0)
    {
        res[0] = one;
    }
    return res;
}





int main()
{
    //int a[] = {1,1,1,2,2,2,2,6,6,20};
    //int a[] = { 1, 9, 9, 7 };
    int a[] = { 1, 9, 9, 9 };
    int len = sizeof(a)/sizeof(int);
    int *res_point;
    res_point = PlusOne(a, len);
    print_array(res_point, len);
    printf("\n");
    return 0;
}

