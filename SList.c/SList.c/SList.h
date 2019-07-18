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
void SListInit(SListNode **pphead);//��ʼ��
SListNode *BuySListNode(SLTDataType x);//����һ���½ڵ�
void SListDestory(SListNode **pphead);//�ݻ�
void SListPushFront(SListNode **pphead, SLTDataType x);//ǰ��
void SListPopFront(SListNode **pphead);//ǰɾ
SListNode *SListFind(SListNode *pphead,SLTDataType x);//��ֵΪx�Ľڵ�
void SListInsertAfter(SListNode *pos, SLTDataType x);//��pos�ĺ������ֵΪx�Ľڵ�
void SListEraseAfter(SListNode *pos);//��ɾ
void SListRemove(SListNode **pphead, SLTDataType x);//ɾ��
void SListRemoveAll(SListNode **pphead, SLTDataType x);//ɾ������
void SListPrint(SListNode *phead);//��ӡ
#endif