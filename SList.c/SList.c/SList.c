#include "SList.h"
SListNode *BuySListNode(SLTDataType x)//申请一个值为x的新节点
{
	SListNode *res =(SListNode*) malloc(sizeof(SListNode));
	res->data = x;
	res->next = NULL;
	return res;
}
void SListInit(SListNode **pphead)//初始化
{
	*pphead = NULL;
}
void SListDestory(SListNode **pphead)//摧毁
{
	if (*pphead == NULL)//判断头节点是否为空
	{
		return;
	}
	while ((*pphead)->next)//依次删除头节点的下一个节点
	{
		SListEraseAfter(*pphead);
	}
	free(*pphead);//释放头节点
	*pphead = NULL;//头节点值为NULL
}
void SListPushFront(SListNode **pphead,SLTDataType x)//前插
{
	SListNode *tmp = BuySListNode(x);
	tmp->next = *pphead;
	*pphead = tmp;
}
void SListPopFront(SListNode **pphead)//前删
{
	if (*pphead == NULL)
	{
		return;
	}
	SListNode *tmp = (*pphead)->next;
	free(*pphead);
	*pphead = tmp;
}
SListNode *SListFind(SListNode *pphead, SLTDataType x)//查找
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
void SListInsertAfter(SListNode *pos, SLTDataType x)//在pos的后面插入
{
	SListNode *tmp = BuySListNode(x);
	tmp->next = pos->next;
	pos->next = tmp;
}
void SListEraseAfter(SListNode *pos)//后删
{
	SListNode*tmp = pos->next;
	if (tmp == NULL)
	{
		return;
	}
	pos->next = tmp->next;
	free(tmp);
}
void SListRemove(SListNode **pphead, SLTDataType x)//删掉第一个值为x的节点
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
void SListRemoveAll(SListNode **pphead, SLTDataType x)//删掉所有值为x的节点
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