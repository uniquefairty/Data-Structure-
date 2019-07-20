#include "List.h"

int main()
{
	ListNode List;
	ListNode List1;
	ListInit(&List);
	ListInit(&List1);

	ListPushBack(&List,1);
	ListPushBack(&List, 3);
	ListPushBack(&List, 4);
	ListPushBack(&List, 5);
	ListPushBack(&List, 9);
	

	//ListPrint(&List);


	ListPushBack(&List1, 2);
	ListPushBack(&List1, 5);
	ListPushBack(&List1, 7);
	ListPushBack(&List1, 10);
	//ListPrint(&List1);

	//ListPushFront(&List, 3);
	//ListPushFront(&List, 2);
	//ListPushBack(&List, );
	//ListPushFront(&List, 66);
	//ListPrint(&List);

	//ListPushBack(&List, 5);
	//ListPopFront(&List);
 //   ListPrint(&List);

	//ListRemove(&List, 6);
	////ListPopBack(&List);
	//ListPrint(&List);

	//deleteDuplication(&List);
	mergeTwoLists(&List,&List1);
	
	ListPrint(&List);

	ListDestory(&List);
	system("pause");
	return 0;
}