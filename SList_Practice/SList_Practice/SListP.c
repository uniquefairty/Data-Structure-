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
void SListEraseAfter(SListNode *pos)//��ɾ
{
	SListNode*tmp = pos->next;
	if (tmp == NULL)
	{
		return;
	}
	pos->next = tmp->next;
	free(tmp);
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

//��תһ��������
void reaversal(SListNode **pphead)//���Ϻ�ɾǰ�����
{
	SListNode *head = *pphead;//��ָ����ÿ��ѭ����ʼ��ָ��ǰ�����ͷ
	SListNode *oldp = head;//��ָ����ÿ��ѭ����ʼ��ָ��ԭ����ͷ�ڵ㣬����ı䷽��
	SListNode *tmp = head->next;//��ָ����ÿ��ѭ����ʼ��ָ��Ҫ����ɾ��ͷ��Ľڵ�
	while (tmp)//���tmpΪ�գ�����������������ͷ��next�Ѿ��ǿյ��ˣ���Ϊ�������β
	{
		oldp->next = tmp->next;//��tmp�ܿգ�ʵ���Ǻ�ɾ������һ����
		tmp->next = head;//��tmp����µ�ͷ��ʵ����ͷ�������һ����
		head = tmp;//��ͷ
		tmp = oldp->next;//��tmp����´�ѭ���д�ɾ���Ľڵ�
	}
	*pphead = head;
}
void reaversal_1(SListNode **pphead)
{
	SListNode *pre= *pphead;//��ִ�в�����ǰһ���ڵ�
	SListNode *cur = pre->next;//��ִ�в����Ľڵ�
	SListNode *nex = cur;//��ִ�в����ĺ�һ���ڵ㣬��ʱָ��cur����ѭ����ʼʱָ����һ���ڵ�
	pre->next = NULL;//��ʱ��ͷ��������ת�����β������������������β�ڵ�
	while (nex)
	{
		nex = nex->next;//����nex�����һ���ڵ㣬֮���Բ������������Ϊ����nexΪ�յ�����
		cur->next = pre;//��ԭ��ָ�ź����ָ��ǰ���������ת��
		pre = cur;//Ϊ���´�ѭ�����������ݣ������������´�ѭ������һ���ڵ㣨����ִ�в����Ľڵ㽫����´�ѭ������һ���ڵ㣩
		cur = nex;//ͬ�ϣ����ε���һ���ڵ㽫���Ϊ�´εı�ִ�нڵ㣩
	}
	*pphead = pre;//ѭ��������cur��next���Ѿ�ָ��գ�pre�����µ�ͷ
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

