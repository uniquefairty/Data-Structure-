#include "SList.h"
SListNode *BuySListNode(SLTDataType x)//����һ��ֵΪx���½ڵ�
{
	SListNode *res =(SListNode*) malloc(sizeof(SListNode));
	res->data = x;
	res->next = NULL;
	return res;
}
void SListInit(SListNode **pphead)//��ʼ��
{
	*pphead = NULL;
}
void SListDestory(SListNode **pphead)//�ݻ�
{
	if (*pphead == NULL)//�ж�ͷ�ڵ��Ƿ�Ϊ��
	{
		return;
	}
	while ((*pphead)->next)//����ɾ��ͷ�ڵ����һ���ڵ�
	{
		SListEraseAfter(*pphead);
	}
	free(*pphead);//�ͷ�ͷ�ڵ�
	*pphead = NULL;//ͷ�ڵ�ֵΪNULL
}
void SListPushFront(SListNode **pphead,SLTDataType x)//ǰ��
{
	SListNode *tmp = BuySListNode(x);
	tmp->next = *pphead;
	*pphead = tmp;
}
void SListPopFront(SListNode **pphead)//ǰɾ
{
	if (*pphead == NULL)
	{
		return;
	}
	SListNode *tmp = (*pphead)->next;
	free(*pphead);
	*pphead = tmp;
}
SListNode *SListFind(SListNode *pphead, SLTDataType x)//����
{
	SListNode *tmp ;
	for (tmp = pphead; tmp; tmp->next)
	{
		if (tmp->data == x)
		{
			return tmp;
		}
	}
	return NULL;
}
void SListInsertAfter(SListNode *pos, SLTDataType x)//��pos�ĺ������
{
	SListNode *tmp = BuySListNode(x);
	tmp->next = pos->next;
	pos->next = tmp;
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
void SListRemove(SListNode **pphead, SLTDataType x)//ɾ����һ��ֵΪx�Ľڵ�
{
	if (*pphead == NULL)
	{
		return;
	}
	SListNode *tmp = *pphead;
	if ((*pphead)->data == x)
	{
		SListEraseAfter(pphead);
		return;
	}
	for (tmp = *pphead; tmp->next; tmp = tmp->next)
	{
		if (tmp->next->data == x)
		{
			SListEraseAfter(tmp);
			return;
		}
	}
}
void SListRemoveAll(SListNode **pphead, SLTDataType x)//ɾ������ֵΪx�Ľڵ�
{
	SListNode *tmp;
	if (*pphead && (*pphead)->data == x)
	{
		SListPopFront(pphead);
	}
	for (tmp = *pphead; tmp&&tmp->next;)
	{
		if (tmp->next->data == x)
		{
			SListEraseAfter(tmp);
		}
		else
		{
			tmp = tmp->next;
		}

	}
}
void SListPrint(SListNode *phead)
{
	SListNode *tmp = phead;
	for (tmp = phead; tmp; tmp = tmp->next)
	{
		printf("%d->", tmp->data);
	}
	printf("NULL\n");
}