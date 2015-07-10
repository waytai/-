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



int **threesum(int* nums, int numsize, int *returnsize)
{
    int i,j,a, m,n ,b,c;
    int t =0;
    int **res;
    res =(int**)malloc(sizeof(int*));
    for(i=0; i<numsize; i++)
    {
        a = nums[i];
        m = i+1;
        n = numsize -1;
        while(m<n && m >= i+1 && n<= numsize-1)
        {
           b = nums[m];
           c = nums[n];
            if(b+c > -a)
            {
                n--;
            }
            else if(b+c < -a)
            {
                m++;
            }
            else
            {

               res = (int**)realloc(res,sizeof(int *));
               res[t] = (int*)malloc(sizeof(int)*3);
               res[t][0] = nums[i];
               res[t][1] = nums[m];
               res[t][2] = nums[n];
              // m++;
              // n--;
               t++;
               *returnsize = t;
               break;
            }
        }

    }
    return res;
}

 
int main()
{
    int a[] = {-1, 0, 1, 2, -1, -4};
    int numsize = sizeof(a)/sizeof(int);
    int returnsize = 0;
    shell_sort(a, numsize);
    print_array(a, numsize);
    printf("\n");
    int **ret;
    ret = threesum(a, numsize, &returnsize);
    printf("retrunsize is %d\n", returnsize);
    int i,j;

    for(i=0; i< returnsize; i++)
    {
        for(j=0; j<3 ; j++)
        {
            printf("--- %d  ", ret[i][j]);
        }
        printf("\n");
    }
    
    for(i=0; i< returnsize; i++)
    {
        free(ret[i]);
    }
    free(ret);
    printf("\n");
    return 0;
}
