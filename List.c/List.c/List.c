#include "List.h"

void ListInit(List *plist)
{
	plist->_head= (ListNode *)malloc(sizeof(ListNode));
	plist->_head->_next = plist->_head;
	plist->_head->_prev = plist->_head;
}

void ListDestory(List *plist)//摧毁
{
	while (plist->_head != plist->_head->_next)
	{
		ListPopFront(plist);
	}
	free(plist->_head);
	plist->_head = NULL;

}

void ListPushBack(List *plist, LTDataType x)//后插
{
	ListInsertFront(plist->_head,x);
}
void ListPopBack(List *plist)//后删
{
	ListErase(plist->_head ->_prev);
}
void ListPushFront(List *plist, LTDataType x)//前插
{
	ListInsertAfter(plist->_head , x);
}
void ListPopFront(List *plist)//前删
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
#if 1
	ListNode *cur = (ListNode *)malloc(sizeof(ListNode));
	ListNode *tmp = pos->_prev;

	cur->_data = x;

	pos->_prev = cur;
	cur->_next = pos;
	tmp->_next = cur;
	cur->_prev = tmp;
#else
	ListNode *tmp = (ListNode *)malloc(sizeof(ListNode));
	/*tmp->_data = x;
	tmp->_prev = pos->_prev;
	tmp->_prev->_next = tmp;
	tmp->_next = pos;
	pos->_prev = tmp;*/

	tmp->_data = x;
	tmp->_next = pos;
	tmp->_prev = pos->_prev;
	pos->_prev = tmp;
	tmp->_prev->_next = tmp;
#endif
}

void ListInsertAfter(ListNode *pos, LTDataType x)//在pos位后面插入
{
#if 1
	ListNode *cur = (ListNode *)malloc(sizeof(ListNode));
	ListNode *tmp = pos->_next;

	cur->_data = x;

	pos->_next = cur;
	cur->_prev = pos;
	tmp->_prev = cur;
	cur->_next = tmp;

#else
	ListNode *tmp = (ListNode *)malloc(sizeof(ListNode));
	tmp->_data = x;
	tmp->_prev = pos;
	tmp->_next = pos->_next;
	pos->_next = tmp;
	tmp->_next->_prev = tmp;
#endif
}

void ListErase(ListNode *pos)
{
	pos->_prev->_next = pos->_next;
	pos->_next->_prev = pos->_prev;
	free(pos);
}
void ListRemove(List *plist, LTDataType x)
{
	ListNode *tmp = ListFind(plist,x);
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
	printf("Head\n");
}
