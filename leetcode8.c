/*************************************************************************
    > File Name: leetcode8.c
    > Author: wayne
    > Mail: @163.com 
    > Created Time: 2015年07月09日 星期四 15时52分33秒
    3sum
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

void swap(int *x, int *y)
{
    int tmp;
    tmp = *x;
    *x = *y;
    *y = tmp;

}

void print_array(int a[], int n)
{
    int i;
    for(i =0 ; i<n ;i++)
    {
        printf("%d  ", a[i]);
    }
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



void threesum(int* nums, int numsize, int *returnsize)
{
    int i,j,a, m,n ,b,c;
    int t =0;
    for(i=0; i<numsize; i++)
    {
        a = nums[i];
        m = i+1;
        n = numsize -1;
        while(m<n && m>=0 && n>=0)
        {
           b = nums[m];
           c = nums[n];
            if(b+c > -a)
            {
                n--;
            }
            else if(b+c < -a)
            {
                m--;
            }
            else
            {
                printf("-- %d  %d  %d",i, m,n);
                printf("\n");
                printf("*** %d  %d  %d",nums[i], nums[m], nums[n]);
                m--;
                n--;
                printf("\n");
                t++;
                //break;
            }
        }

    }
}

 
int main()
{
    int a[] = {-1, 0, 1, 2, -1, -4};
    int numsize = sizeof(a)/sizeof(int);
    int returnsize = 3;
    shell_sort(a, numsize);
    print_array(a, numsize);
    printf("\n");
    threesum(a, numsize, &returnsize);
    printf("\n");
    return 0;
}
