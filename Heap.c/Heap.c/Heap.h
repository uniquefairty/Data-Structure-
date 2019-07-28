#ifndef _HEAP_H_
#define _HEAP_H_

#include<stdio.h>
#include<Windows.h>
#include<string.h>

#define MAXSIZE 100
typedef int HPDataType;
typedef struct Heap
{
	HPDataType * _data;
	int _size;
	int _capacity;
}Heap;

void DownAdjust(Heap *hp, int n);//堆向下调整法，n是下标

void HeapInit(Heap *hp, HPDataType *a, HPDataType n);//数组不是堆，调整为堆，从倒数第一个非叶子节点开始，直到根节点
void HeapDestory(Heap *hp);

void HeapPush(Heap *hp, HPDataType x);
void HeapPop(Heap *hp);//删除堆顶元素

HPDataType HeapTop(Heap *hp);
int _HeapSize(Heap *hp);
int HeapEmpty(Heap *hp);
// 堆排序

void HeapPrint(Heap *hp);
void HeapSort(Heap *hp );
void TestHeap();

#endif/*_HEAP_H_*/