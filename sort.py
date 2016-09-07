#########################################################################
#-*- coding:utf-8 -*-
# File Name: sort.py
#########################################################################
#!/bin/python

a = [7,2,8,98,1]

def buble_sort(alist):
    len_list = len(alist)
    for i in range(len_list):
        for j in range(i+1,len_list):
            if a[i] > a[j]:
                a[i],a[j] = a[j],a[i]
    return alist

print buble_sort(a)
