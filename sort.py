#########################################################################
#-*- coding:utf-8 -*-
# File Name: sort.py
#########################################################################
#!/bin/python

a = [7,2,8,98,1]

def bubble_sort(alist):
    len_list = len(alist)
    for i in range(len_list):
        for j in range(i+1,len_list):
            if a[i] > a[j]:
                a[i],a[j] = a[j],a[i]
    return alist

print bubble_sort(a)


def insert_sort(alist):
    len_list = len(alist)
    for i in range(len_list):
        index = a[i]
        for j in range(i+1, len_list):
            if a[j] > index:
                a[i], a[j] = a[j], a[i]
            else:
                index = a[j]
    return alist

print insert_sort(a)


                
