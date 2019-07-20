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

//******************************************************************
//在一个有序的链表中，删除重复的结点，重复的结点不保留
void deleteDuplication(List* plist)
{
	ListNode *cur;
	for (cur = plist->_head->_next; cur != plist->_head->_prev;)
	{
		if (cur->_data == cur->_next->_data)
		{
			ListErase(cur->_next);//不能删掉cur，若删掉cur，下次循环就找不到cur的值，或者可以执行删除下一个节点操作
		}
		else
		{
			cur = cur->_next;
		}
	}
}
//********************************************************************
//将两个有序链表合并为一个新的有序链表并返回，新链表是通过拼接给定的两个链表的所有节点
ListNode* mergeTwoLists(List *plist, List* plist2)
{
	ListNode *cur1=plist->_head->_next;
	ListNode *cur2=plist2->_head->_next;
	ListNode *tmp;

	while (cur1!=plist->_head  &&cur2!=plist->_head )//双链表遍历的跳出条件
	{
		if (cur1->_data < cur2->_data)
		{
			cur1 = cur1->_next;
		}
		else
		{
			tmp = cur2;//要把cur2插进list中，保护在list2中遍历的指针
			cur2 = cur2->_next;//指向下次需要比较的节点

			cur1->_prev->_next = tmp;
			tmp->_prev = cur1->_prev;
			tmp->_next = cur1;
			cur1->_prev = tmp;
		}
	}
	//如果遍历结束后，list到末尾了，证明list2还没结束（两个肯定不会同时到末尾），而且list2剩下的节点都比list大，所以要把list2剩下的节点插进list的后面
	if (cur1 == plist->_head)
	{
		cur1->_prev ->_next = cur2;
		cur2->_prev = cur1->_prev;

		cur1->_prev = plist2->_head->_prev;
		plist2->_head->_prev->_next = cur1;
	}
	free(plist2->_head);
}
