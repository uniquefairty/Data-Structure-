#include "List.h"

int main()
{

	ListNode List;
	ListInit(&List);
	ListPushBack(&List, 8);
	ListPushBack(&List, 7);
	ListPushBack(&List, 6);
	ListPushBack(&List, 5);
	ListPushBack(&List, 4);

	ListPushFront(&List, 10);
	ListPushFront(&List, 23);

	ListPushFront(&List, 66);
	ListPrint(&List);

	ListPopFront(&List);
    ListPrint(&List);

	ListRemove(&List, 6);

	//ListPopBack(&List);
	ListPrint(&List);
	ListDestory(&List);
	system("pause");
	return 0;
}