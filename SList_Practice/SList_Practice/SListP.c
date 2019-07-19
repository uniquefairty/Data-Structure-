#include "SListP.h"
SListNode* BuySLiseNode(SLTDataType x)
{
	SListNode *res = (SListNode *)malloc(sizeof(SListNode));
	res->data = x;
	res->next = NULL;
}
void SListInit(SListNode **pphead)
{
	*pphead = NULL;
}
void SListPushFront(SListNode **pphead, SLTDataType x)
{
	SListNode *tmp = BuySLiseNode(x);
	if (*pphead == NULL)
	{
		*pphead = tmp;
		return;
	}
	tmp->next = *pphead;
	*pphead = tmp;
}
void SListPrint(SListNode *phead)
{
	SListNode *tmp = phead;
	for(tmp = phead; tmp; tmp = tmp->next)
	{
		printf("%d->", tmp->data);
	}
	free(tmp);
//	tmp->next = NULL;
	printf("NULL\n");
}

//反转一个单链表
void reaversal(SListNode **pphead)//不断后删前插操作
{
	SListNode *head = *pphead;//
	SListNode *oldp = head;//
	SListNode *tmp = NULL;
	while (oldp->next)
	{
		tmp = oldp->next;
		oldp->next = tmp->next;
		tmp->next = head;
		head = tmp;
	}
	*pphead = head;
}
void reaversal_1(SListNode **pphead)
{
	SListNode *pre= *pphead;//被执行操作的前一个节点
	SListNode *cur = pre->next;//被执行操作的节点
	SListNode *nex = cur;//被执行操作的后一个节点，暂时指向cur，在循环开始时指向下一个节点
	pre->next = NULL;//此时的头，将会是转化后的尾，这里是在设置链表尾节点
	while (nex)
	{
		nex = nex->next;//先让nex变成下一个节点，之所以不放在最后，是因为会有nex为空的限制
		cur->next = pre;//让原本指着后面的指到前面来（向后转）
		pre = cur;//为了下次循环而传递数据，这里是设置下次循环的上一个节点（本次执行操作的节点将会成下次循环的上一个节点）
		cur = nex;//同上（本次的下一个节点将会成为下次的被执行节点）
	}
	*pphead = pre;//循环跳出后cur和next都已经指向空，pre才是新的头
}

SListNode *getIntersectionNode(SListNode *headA, SListNode *headB)
{
	int lenA = 0;
	int lenB = 0;
	SListNode *cur=NULL;
	SListNode *longer=headA;
	SListNode *shorter=headB;
	int gap;
	int i;
	for (cur = headA; cur; cur = cur->next)
	{
		lenA++;
	}
	for (cur =headB; cur; cur = cur->next)
	{
		lenB++;
	}
	gap = abs(lenA - lenB);
	if (lenA < lenB)
	{
		longer = headB;
		shorter = headA;
	}
	for (i = 0; i < gap; i++)
	{
		longer = longer->next;
	}
	for (; longer && shorter; longer = longer->next, shorter=shorter->next)
	{
		if (longer == shorter)
		{
			return shorter;
		}
	}
	return NULL;
}

SListNode *detectCycle(SListNode *phead)
{
	
	SListNode *fast = phead;
	SListNode *slow = phead;

	while (fast&&slow&&fast->next)
	{
		fast = fast->next->next;
		slow = slow->next;
		if (fast == slow)
		{
			break;
		}
	}
	for (; fast&&fast->next; fast = fast->next, phead = phead->next)
	{
		if (fast = phead)
		{
			return fast;
		}
	}
	return NULL;
}

