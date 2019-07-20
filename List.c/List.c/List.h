#ifndef _LIST_H
#define _LIST_H

#include<stdio.h>
#include<Windows.h>

typedef int LTDataType;
typedef struct ListNode
{
	LTDataType _data;
	struct ListNode *_next;
	struct ListNode *_prev;
}ListNode;

typedef struct List
{
	ListNode *_head;
}List;

void ListInit(List *plist);
void ListPushBack(List *plist, LTDataType x);//后插
void ListPopBack(List *plist);//后删

void ListPushFront(List *plist, LTDataType x);//前插
void ListPopFront(List *plist);//前删

ListNode *ListFind(List *plist, LTDataType x);

void ListInsertFront(ListNode *pos, LTDataType x);//在pos位前面插入
void ListInsertAfter(ListNode *pos, LTDataType x);//在pos位后面插入

void ListErase(ListNode *pos);//删除pos位置的节点
void ListRemove(List *plist, LTDataType x);//移除p值为x的节点

void ListDestory(List *plist);//摧毁

void ListPrint(List *plist);

#endif