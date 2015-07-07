/*************************************************************************
    > File Name: leetcode3.c
    > Author: wayne
    > Mail: @163.com 
    > Created Time: 2015年07月07日 星期二 17时09分16秒
    允许最多两个同样的元素存在于排序好的数组中
    例如：a = [1,1,1,2,2,3]
    函数将返回 5 新的数组为a = [1,1,2,2,3]
 ************************************************************************/

#include<stdio.h>

void print_array(int a[], int n)
{
    int i;
    for(i =0 ; i<n ;i++)
    {
        printf("%d  ", a[i]);
    }
}

int removeDuplicates(int a[], int len)
{
    int i,j = 0 ,num;
    if(0 == len)
        return 0;
    for(i=1; i<len; i++)
    {
        if(a[j] != a[i]) 
        {
            a[++j] = a[i];
            continue;
        }
        else if(a[j] == a[i])
        {
            num++;
            if(num !=2)
            {
                continue;
            }
            else 
            {
                num = 0;
                a[++j] = a[i];
            }

        }
    }
    return j+1;

}


int main()
{
    int a[] = {1,1,1,2,2,2,2,6,6,20};
    int len = sizeof(a)/sizeof(int);
    int len_remove;
    len_remove =  removeDuplicates(a, len);
    printf("%d\n", len_remove);
    print_array(a, len_remove);
    printf("\n");
    return 0;
}

