#ifndef _SORT_H
#define _SORT_H

#include<stdio.h>
#include<windows.h>

#define ARRSIZE (sizeof(a)/sizeof(a[0]))

void mergeSort(int *arr, int n);//归并排序 //排序接口，排arr，n个

void Qsort(int *arr, int n);//快速排序

#endif/*_SORT_H*/