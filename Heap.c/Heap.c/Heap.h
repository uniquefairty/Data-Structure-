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

void DownAdjust(Heap *hp, int n);//�����µ�������n���±�

void HeapInit(Heap *hp, HPDataType *a, HPDataType n);//���鲻�Ƕѣ�����Ϊ�ѣ��ӵ�����һ����Ҷ�ӽڵ㿪ʼ��ֱ�����ڵ�
void HeapDestory(Heap *hp);

void HeapPush(Heap *hp, HPDataType x);
void HeapPop(Heap *hp);//ɾ���Ѷ�Ԫ��

HPDataType HeapTop(Heap *hp);
int _HeapSize(Heap *hp);
int HeapEmpty(Heap *hp);
// ������

void HeapPrint(Heap *hp);
void HeapSort(Heap *hp );
void TestHeap();

#endif/*_HEAP_H_*/