#include<stdio.h>
#include<stdlib.h>


int main()
{
int *a, i;
a = (int*)malloc(sizeof(int));
a = realloc(a, sizeof(int)*10);
for(i=0; i<10; i++)
{
 a[i] = 10;
 printf("%d  ", a[i]);
}
printf("\n");
printf("%d\n", i);
printf("%d  \n", a[i]);
return 0;
}
