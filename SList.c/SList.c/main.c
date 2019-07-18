#include "SList.h"
int main()
{
	SListNode *phead;
	SListInit(&phead);
	SListPushFront(&phead, 4);
	SListPushFront(&phead, 5);
	SListPushFront(&phead, 4);
	SListPushFront(&phead, 4);
	SListPushFront(&phead, 6);
	SListPushFront(&phead, 4);
	//SListPopFront(&phead);
	//
	//SListRemove(&phead, 6);
	SListRemoveAll(&phead, 10);
	SListPrint(phead);
	SListDestory(&phead);
	system("pause");
	return 0;
}