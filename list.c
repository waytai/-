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

int main()
{
    list_s *list_b;

    int i;
    for(i=0; i<10; i++)
    {
        insert_list_tail(list_b, i);
    }

    for(i=0; i<10; i++)
    {
        printf("%d\n", list_b->data);
        list_b =list_b->next; 
    }
    return 0;
}
