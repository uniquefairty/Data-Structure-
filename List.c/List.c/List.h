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
//****************带头双向循环链表增删查改实现************
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
 //***********************************************************


//在一个有序的链表中，删除重复的结点，重复的结点不保留
void deleteDuplication(ListNode* plist);
//****************************************************
//将两个有序链表合并为一个新的有序链表并返回，
//新链表是通过拼接给定的两个链表的所有节点
ListNode* mergeTwoLists(List *plist, List* list1);
//

#endif