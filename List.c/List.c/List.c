#include "List.h"

void ListInit(List *plist)
{
	plist->_head= (ListNode *)malloc(sizeof(ListNode));
	plist->_head->_next = plist->_head;
	plist->_head->_prev = plist->_head;
}
void ListPushBack(List *plist, LTDataType x)//后插
{
	ListInsertFront(&plist->_head,x);
}
void ListPopBack(List *plist, LTDataType x)//后删
{
	ListErase(plist->_head ->_prev);
}
void ListPushFront(List *plist, LTDataType x)//前插
{
	ListInsertAfter(&plist->_head , x);
}
void ListPopFront(List *plist, LTDataType x)//前删
{
	ListErase(plist->_head->_next );

}

ListNode *ListFind(List *plist, LTDataType x)
{
	ListNode *cur;
	for (cur = plist->_head->_next; cur != plist->_head; cur = cur->_next)
	{
		if (cur->_data == x)
		{
			return cur;
		}
	}
	return NULL;
}
void ListInsertFront(ListNode *pos, LTDataType x)//在pos位前面插入
{
	ListNode *cur = (ListNode *)malloc(sizeof(ListNode));
	ListNode *tmp = pos->_prev;

	cur->_data = x;

	pos->_prev = cur;
	cur->_next = pos;
	tmp->_next = cur;
	cur->_prev = tmp;

	/*tmp->_data = x;
	tmp->prev = pos->prev;
	tmp->prev->_next = tmp;
	tmp->_next = pos;
	pos->prev = tmp;*/
	/*tmp->_next = pos;
	tmp->prev = pos->prev;
	pos->prev = tmp;
	tmp->prev->_next = tmp;*/
}

void ListInsertAfter(ListNode *pos, LTDataType x)//在pos位后面插入
{
	ListNode *cur = (ListNode *)malloc(sizeof(ListNode));
	ListNode *tmp = pos->_next;

	cur->_data = x;

	pos->_next = cur;
	cur->_prev = pos;
	tmp->_prev = cur;
	cur->_next = tmp;

	/*ListNode *tmp = (ListNode *)malloc(sizeof(ListNode));
	tmp->_data = x;
	tmp->_prev = pos;
	tmp->_next = pos->_next;
	pos->_next = tmp;
	tmp->_next->_prev = tmp;*/
}

void ListErase(ListNode *pos)
{
	pos->_prev->_next = pos->_next;
	pos->_next->_prev = pos->_prev;
	free(pos);
}
void ListRemove(List *plist, LTDataType x)
{
	ListNode *tmp = ListFind(&plist,x);
	if (tmp)
	{
		ListErase(tmp);
	}
	
}
void ListPrint(List *plist)
{
	ListNode *cur;
	printf("Head->");

	for (cur = plist->_head->_next; cur != plist->_head; cur = cur->_next)
	{
		printf("%d->", cur->_data);
	}
	printf("Head");
}

//svn