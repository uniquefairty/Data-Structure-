#include "SListP.h"

int main()
{
	//反转一个单链表
	SListNode *phead;
	//SListNode *phead1;

	SListNode *tmp;
	SListNode *tmp2;
	
	SListInit(&phead);
	//SListInit(&phead1);

	SListPushFront(&phead, 1);
	SListPushFront(&phead, 2);
	//tmp = phead;
	SListPushFront(&phead, 3);
	SListPushFront(&phead, 4);
	
	SListPushFront(&phead, 5);
	//tmp2 = phead;
	SListPushFront(&phead, 6);
	reaversal(&phead);
	//reaversal_1(&phead);
	SListPrint(phead);


	//SListPushFront(&phead1, 10);
	//cur = phead1;
	//cur->next = tmp;

	//SListPushFront(&phead1, 4);
	SListPushFront(&phead, 11);
	SListPushFront(&phead, 34);
	//SListPushFront(&phead1, 6);
//	tmp->next = tmp2;
	//SListPrint(phead1);
	//detectCycle(phead);

	/*SListNode *ret = detectCycle(phead);
	if (ret)
	{
		printf("%d", ret->data);
	}
	else
	{
		printf("NULL\n");
	}*/
	//SListNode *ret = getIntersectionNode(phead, phead1);
	


	system("pause");
	return 0;
}