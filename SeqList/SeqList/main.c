#include "SeqList.h"
int main()
{
	SeqList psl;

	SeqListInit(&psl, 2);
	//CheckCapacity(&psl);
	SeqListPushBack(&psl, 1);
	SeqListPushBack(&psl, 2);
	SeqListPushBack(&psl, 3);
	SeqListPushBack(&psl, 9);
	SeqListPushBack(&psl, 4);
	SeqListPushBack(&psl, 9);
	//SeqListPopBack(&psl);

	SeqListPushFront(&psl, 10);
	//SeqListPushFront(&psl, 9);
	//SqListBubbleSort(&psl);

	//printf("\n");


	SeqListInsert(&psl, 7, 100);
	SeqListPrint(&psl);
	SeqListErase(&psl, 4);
	//SeqListRemoveAll(&psl, 9);
	//SeqListPopFront(&psl);

	//SeqListInsert(&psl, 2, 6);
	//SeqListErase(&psl, 2);

	int res = SeqListBinaryFind(&psl, 4);
	printf("%d\n", res);

	/*int res=SeqListFind(&psl, 2);
	printf("%d\n", res);*/
	SeqListPrint(&psl);
	SeqListDestory(&psl);
	system("pause");
	return 0;
}