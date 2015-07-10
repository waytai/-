/*************************************************************************
    > File Name: search_for_a_range.c
    > Author: wayne
    > Mail: @163.com 
    > Created Time: 2015年07月10日 星期五 10时16分26秒
 ************************************************************************/

#include<stdio.h>

int binary_search(int a[],int l, int r, int target)
{
    if(l <= r)
    {
        int mid = l+ (r-1)/2;
        if(a[mid] == target)
        {
            return mid;
        }
        else if(target < a[mid])
        {
            binary_search(a, l, mid-1, target);
        }
        else
        {
            binary_search(a, mid+1, r, target);
        }

        }
    }

int main()
{
    int a[] = {5,7,7,8,8,10};
    int len = sizeof(a)/sizeof(int);
    printf("%d\n", len);
    int target = 8;
    int ret;
    ret = binary_search(a, 0, len-1, target);
    printf("%d\n", a[ret]);
    printf("%d\n", ret);
    return 0;
}

