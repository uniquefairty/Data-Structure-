#ifndef _SLISTP_H_
#define _SLISTP_H_

#include<stdio.h>
#include<Windows.h>
#include<math.h>

typedef int SLTDataType;

typedef struct SListNode
{
	SLTDataType *data;
	struct SListNode* next;
}SListNode;

void SListInit(SListNode **pphead);
SListNode* BuySLiseNode(SLTDataType x);
void SListPushFront(SListNode **pphead, SLTDataType x);

void SListPrint(SListNode *phead);

void reaversal(SListNode **pphead);
void reaversal_1(SListNode **pphead);


SListNode *getIntersectionNode(SListNode *headA, SListNode *headB);

SListNode *detectCycle(SListNode *phead);
//void Fun9(SListNode **pphead, SListNode **pphead1);

//void Fun10(SListNode **pphead, SListNode **pphead1);




#endif