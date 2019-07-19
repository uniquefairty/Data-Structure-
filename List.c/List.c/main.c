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

	ListPrint(&List);
	system("pause");
	return 0;
}