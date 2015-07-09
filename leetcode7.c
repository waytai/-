#include<stdio.h>

void find_index(int a[], int target, int len, int t[2])
{
    int i,j;
    for(i = 0; i<len; i++)
    {
        for(j = i+1; j<len; j++)
        {
            if(target == (a[i] + a[j]))
            {
                t[0] = i;
                t[1] = j;
            }

        }
    }

}

int main()
{
    int a[] = {2, 7, 11, 15};
    int target = 9;
    int t[2], i;
    int len  = sizeof(a)/sizeof(int);
    find_index(a, target, len, t);
    for(i=0; i<2; i++)
    {
        printf("index %d is %d ", i, a[i]);
    }
    printf("\n");
    return 0;
}
