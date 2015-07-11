#include<stdio.h>
#include<stdlib.h>


int *rotate_array(int a[], int len, int index)
{
 int i;
 int *b;
 b = (int*)malloc(sizeof(int)*len);
 for(i=index; i<len; i++)
	{
	b[i-index] = a[i];
	}
 for(i=0; i<index; i++)
	{
	b[index+i] = a[i];
	}
return b;
}


int find_min_ele(int c[], int len)
{
  int min_ele,i;
  for(i=0,min_ele=c[0]; i<len; i++)
	{
	 if(min_ele>c[i])
	{
	 min_ele = c[i];
	}
	}
return min_ele;
}


int search_min(int c[], int len)
{
 int min_ele,i, index;
 index = (len-1)/2;
 if (c[index] > c[0]) 
  { 
   }
 else if (c[index] < c[0]) 
  { 
   }

}

int main()
{
int a[] = {0, 1, 2, 3, 4, 5, 6, 7};
int index = 4;
int len = sizeof(a)/sizeof(int);
int *rotated_array;
rotated_array = rotate_array(a, len, index);
int i;
for(i=0; i<len; i++)
{
printf("%d  ", rotated_array[i]);
}
printf("\n");
int min;
min = find_min_ele(rotated_array, len);
printf("%d\n", min);
printf("\n");
return 0;
}
