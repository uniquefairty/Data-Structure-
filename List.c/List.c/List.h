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
void ListPushBack(List *plist, LTDataType x);//���
void ListPopBack(List *plist);//��ɾ

void ListPushFront(List *plist, LTDataType x);//ǰ��
void ListPopFront(List *plist);//ǰɾ

ListNode *ListFind(List *plist, LTDataType x);

void ListInsertFront(ListNode *pos, LTDataType x);//��posλǰ�����
void ListInsertAfter(ListNode *pos, LTDataType x);//��posλ�������

void ListErase(ListNode *pos);//ɾ��posλ�õĽڵ�
void ListRemove(List *plist, LTDataType x);//�Ƴ�pֵΪx�Ľڵ�

void ListDestory(List *plist);//�ݻ�

void ListPrint(List *plist);

#endif