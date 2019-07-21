#ifndef  _SEQLIST_H
#define  _SEQLIST_H

#include<stdio.h>
#include<Windows.h>
#include<stdlib.h>
#include<string.h>
#include<malloc.h>

typedef int SLDataType;

typedef struct SeqList
{
	SLDataType *array;
	size_t size;
	size_t capacity;
}SeqList;

void SeqListInit(SeqList *psl, size_t capacity);//顺序表初始化
void SeqListDestory(SeqList *psl);//摧毁
void CheckCapacity(SeqList *psl);//检查是否需要扩容

void SeqListPushBack(SeqList *psl,SLDataType x);//向末尾压一个数据
void SeqListPopBack(SeqList *psl);//从末尾出一个数据

void SeqListPushFront(SeqList *psl, SLDataType x);//在首部加一个数据
void SeqListPopFront(SeqList *psl);//删掉首部数据

int SeqListFind(SeqList *psl, SLDataType x);//找值为x的数据
void SeqListInsert(SeqList *psl, size_t pos, SLDataType x);//在下标为pos位加入x
void SeqListErase(SeqList *psl, size_t pos);//插除pos位数据

void SeqListRemove(SeqList *psl, SLDataType x);//移除第一个值为x的数据
void SeqListRemoveAll(SeqList *psl, SLDataType x);//移除所有值为x的数据  时间复杂度O（n）  空间复杂度O（n）
void SeqListRemoveAll_1(SeqList *psl, SLDataType x); //时间复杂度O（n）  空间复杂度O（1）
//void SeqListRemoveAll_2(SeqList* psl, SLDataType x);

void SeqListModify(SeqList *psl, size_t pos, SLDataType x);//修改
void SeqListPrint(SeqList *psl);

void SqListBubbleSort(SeqList *psl);//冒泡排序
int SeqListBinaryFind(SeqList *psl, SLDataType x);//二分查找

#endif