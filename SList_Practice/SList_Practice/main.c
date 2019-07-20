#include "SListP.h"


int main()//约瑟夫环
{
	SListNode *phead;//指向头结点
	SListNode *plast;//指向尾结点
	SListNode *cur;
	SListInit(&phead);
	int i;
	int m = 50, n = 3;
	SListPushFront(&phead, 50);//首次头插
	plast = phead;//首次头插，最后会是尾
	
	for (i = m-1; i >=1; i--)//
	{
		SListPushFront(&phead, i);
	}
	plast->next = phead;//连接成环
	cur = plast;//保持第一个被删除的结点与起始位置相差n-个，
	
	for (; m > 1; m--)//剩最后一个人循环退出
	{
		for (i = 1; i < n; i++)//遍历n-1次找到要进行后删的人
		{
			cur = cur->next;
		}
		SListEraseAfter(cur);//后删
	}
	printf("%d", cur->data);
	free(cur);
	system("pause");
	return 0;
}

int main_()
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
	tmp2 = phead;
	SListPushFront(&phead, 6);
	reaversal(&phead);
	reaversal_1(&phead);
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
