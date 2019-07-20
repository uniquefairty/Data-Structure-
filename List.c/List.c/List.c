#include "List.h"

void ListInit(List *plist)
{
	plist->_head= (ListNode *)malloc(sizeof(ListNode));
	plist->_head->_next = plist->_head;
	plist->_head->_prev = plist->_head;
}

void ListDestory(List *plist)//�ݻ�
{
	while (plist->_head != plist->_head->_next)
	{
		ListPopFront(plist);
	}
	free(plist->_head);
	plist->_head = NULL;

}

void ListPushBack(List *plist, LTDataType x)//���
{
	ListInsertFront(plist->_head,x);
}
void ListPopBack(List *plist)//��ɾ
{
	ListErase(plist->_head ->_prev);
}
void ListPushFront(List *plist, LTDataType x)//ǰ��
{
	ListInsertAfter(plist->_head , x);
}
void ListPopFront(List *plist)//ǰɾ
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
void ListInsertFront(ListNode *pos, LTDataType x)//��posλǰ�����
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

void ListInsertAfter(ListNode *pos, LTDataType x)//��posλ�������
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
//��һ������������У�ɾ���ظ��Ľ�㣬�ظ��Ľ�㲻����
void deleteDuplication(List* plist)
{
	ListNode *cur;
	for (cur = plist->_head->_next; cur != plist->_head->_prev;)
	{
		if (cur->_data == cur->_next->_data)
		{
			ListErase(cur->_next);//����ɾ��cur����ɾ��cur���´�ѭ�����Ҳ���cur��ֵ�����߿���ִ��ɾ����һ���ڵ����
		}
		else
		{
			cur = cur->_next;
		}
	}
}
//********************************************************************
//��������������ϲ�Ϊһ���µ������������أ���������ͨ��ƴ�Ӹ�����������������нڵ�
ListNode* mergeTwoLists(List *plist, List* plist2)
{
	ListNode *cur1=plist->_head->_next;
	ListNode *cur2=plist2->_head->_next;
	ListNode *tmp;

	while (cur1!=plist->_head  &&cur2!=plist->_head )//˫�����������������
	{
		if (cur1->_data < cur2->_data)
		{
			cur1 = cur1->_next;
		}
		else
		{
			tmp = cur2;//Ҫ��cur2���list�У�������list2�б�����ָ��
			cur2 = cur2->_next;//ָ���´���Ҫ�ȽϵĽڵ�

			cur1->_prev->_next = tmp;
			tmp->_prev = cur1->_prev;
			tmp->_next = cur1;
			cur1->_prev = tmp;
		}
	}
	//�������������list��ĩβ�ˣ�֤��list2��û�����������϶�����ͬʱ��ĩβ��������list2ʣ�µĽڵ㶼��list������Ҫ��list2ʣ�µĽڵ���list�ĺ���
	if (cur1 == plist->_head)
	{
		cur1->_prev ->_next = cur2;
		cur2->_prev = cur1->_prev;

		cur1->_prev = plist2->_head->_prev;
		plist2->_head->_prev->_next = cur1;
	}
	free(plist2->_head);
}
