/*************************************************************************
    > File Name: shell_sort.c
    > Author: wayne
    > Mail: @163.com 
    > Created Time: 2015年07月06日 星期一 18时10分16秒
 ************************************************************************/

#include<stdio.h>

void swap(int *x, int *y)
{
    int tmp;
    tmp = *x;
    *x = *y;
    *y = tmp;

}

void shell_sort(int a[],int len)
{
    int inc, i,j, tmp;
    for(inc = len/2; inc>0; inc /= 2)
    {
        for(i=inc;i<len;i++)
        {
            tmp = a[i];
            for(j=i;j>=inc; j-=inc)
            {
                if(tmp<a[j-inc])
                    a[j] = a[j-inc];
                else
                    break;
            }
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

    shell_sort(a, len);
    print_array(a, len);
    printf("\n");
    return 0;
}
