/*************************************************************************
    > File Name: leetcode6.c
    > Author: wayne
    > Mail: @163.com 
    > Created Time: 2015年07月08日 星期三 14时18分32秒
    merge sorted array  leetcode 7
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



void merge_array(int a[], int m, int b[], int n)
{
    int i,j, t;
    i = m-1;
    j = n-1;
    t = m+n-1;
    printf("i j t is %d %d %d\n", i,j,t);
    while(t>=0)
    {
        if(i>0 && j>0)
        {
            if(a[i] > b[j])
            {
                a[t] = a[i];
                i--;
            }
            else
            {
                a[t] = b[j];
                j--;
            }
        }
        else if (i>=0)
        {
            a[t] = a[i];
            i--;
        }
        else if(j>=0)
        {
            a[t] = b[j];
            j--;
        }
         
        t--;
         }
}


int main()
{
    int i, len, m, n;
    m = 1;
    int a[30] = {1, 10, 15};
    int b[] = {2, 11, 14, 18};
    len = sizeof(a)/sizeof(int);

    while(a[m] != 0)
    {
        ++m;
    }
    printf("%d\n", m);

    n = sizeof(b)/sizeof(int);
    printf("%d\n", n);
    printf("\n");

    printf("%d\n",m+n);
    merge_array(a,m,b,n);
    print_array(a, m+n);
    printf("\n");
    return 0;
}

