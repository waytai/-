/*************************************************************************
    > File Name: leetcode9.c
    > Author: wayne
    > Mail: @163.com 
    > Created Time: 2015年07月10日 星期五 16时29分52秒
    3sum closet
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
int threesumcloset(int *nums, int numsize, int target)
{

    int i, a;
    int res;
    int m,n;
    int *distance;
    distance = (int*)malloc(sizeof(int));
    int **index_array;
    int max_num = 1000;
    index_array = (int**)malloc(sizeof(int*));
    for(i=0; i<numsize; i++)
    {
        a = nums[i];
        m = i+1;
        n = numsize-1;
        distance = (int*)realloc(distance, sizeof(int));
        distance[i] = max_num;
        index_array = (int**)realloc(index_array, sizeof(int*));
        while(m < n)
        {
            if((a+ nums[m] +nums[n])>target)
            {
                distance[i] =  (a+ nums[m] +nums[n])-target;
                index_array[i] = (int*)malloc(sizeof(int)*3);
                index_array[i][0] = a;
                index_array[i][1] = nums[m];
                index_array[i][2] = nums[n];
                n--;
            }
            else if((a+ nums[m] +nums[n])<target)
            {
                distance[i] = target-(a+ nums[m] +nums[n]);
                index_array[i] = (int*)malloc(sizeof(int)*3);
                index_array[i][0] = a;
                index_array[i][1] = nums[m];
                index_array[i][2] = nums[n];
                m++;
            }
            else
            {
                distance[i] = 0;
                index_array[i] = (int*)malloc(sizeof(int)*3);
                index_array[i][0] = a;
                index_array[i][1] = nums[m];
                index_array[i][2] = nums[n];

                break;
            }
        }
    }

        for(i=0; i<numsize; i++)
        {
            printf("distance is %d ", distance[i]);
        }
        printf("\n");


        int min_distance;
        min_distance = distance[0];
        int index;
        for(i=1; i<numsize; i++)
        {
            if(min_distance > distance[i])
            {
                min_distance = distance[i];
                index = i;
            }
        }

        printf("min_distance is %d\n", min_distance);

        for(i=0; i<3; i++)
        {
            printf("element is %d  ", index_array[index][i]);
        }
        printf("\n");

        for(i=0; i<3; i++)
        {
            free(index_array[i]);
        }
        free(index_array);


        return min_distance; 
}

int main()
{
    int a[] = {-1, 2, 1, -4};
    int len= sizeof(a)/sizeof(int);
    shell_sort(a, len);
    print_array(a, len);
    printf("\n");
    int target = 1;
    int ab_dis;
    ab_dis = threesumcloset(a, len, target);
    printf("distance is %d\n", ab_dis);
    return 0;
}
