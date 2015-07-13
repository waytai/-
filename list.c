/*************************************************************************
    > File Name: list.c
    > Author: wayne
    > Mail: @163.com 
    > Created Time: 2015年07月13日 星期一 09时35分06秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

typedef struct s_list *p_list;
struct s_list
{
    int data;
    p_list next;
};

typedef struct s_list list_s;


void insert_list_tail(list_s *list_p, int insert_data)
{
    list_s *tmp = (list_s *)malloc(sizeof(list_s));
    tmp->data = insert_data; 
    tmp->next = list_p->next;
    list_p->next = tmp;  
}


void insert_nth(list_s *list_p, int n, int ele)
{
    int t=0;
    list_s *tmp = (list_s *)malloc(sizeof(list_s));
    tmp->data = ele;
    while(t<n)
    {
        list_p = list_p->next;
        t++;
    }
    tmp->next = list_p->next;
    list_p->next = tmp;
}

int main()
{
    list_s *list_b;
    list_b = (list_s *)malloc(sizeof(list_s));
    list_b->data = 100;
    list_s *list_c;
    list_c = list_b;
    int i;
    for(i=0; i<10; i++)
    {
        insert_list_tail(list_b, i);
    }

    int length;
    length =0;
    while(list_b->next != NULL)
    {
        printf("%d  ", list_b->data);
        length++;
        list_b = list_b->next;
    }
    printf("%d\n", list_b->data);
    printf("length of list is %d\n", ++length);

    insert_nth(list_c, 2, 90);


    while(list_c->next != NULL)
    {
        printf("%d  ", list_c->data);
        list_c = list_c->next;
    }
    printf("%d\n", list_c->data);

    return 0;
}











