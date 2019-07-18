#ifndef _SLIST_H_
#define _SLIST_H_
#include<stdio.h>
#include<Windows.h>
typedef int SLTDataType;
typedef struct SListNode
{
	SLTDataType data;
	struct SListNode* next;
}SListNode;
void SListInit(SListNode **pphead);//初始化
SListNode *BuySListNode(SLTDataType x);//申请一个新节点
void SListDestory(SListNode **pphead);//摧毁
void SListPushFront(SListNode **pphead, SLTDataType x);//前插
void SListPopFront(SListNode **pphead);//前删
SListNode *SListFind(SListNode *pphead,SLTDataType x);//找值为x的节点
void SListInsertAfter(SListNode *pos, SLTDataType x);//在pos的后面插入值为x的节点
void SListEraseAfter(SListNode *pos);//后删
void SListRemove(SListNode **pphead, SLTDataType x);//删掉
void SListRemoveAll(SListNode **pphead, SLTDataType x);//删掉所有
void SListPrint(SListNode *phead);//打印
#endif