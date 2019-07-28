#include "Heap.h"

#define ARRSIZE(a) (sizeof(a)/sizeof(a[0]))

int main()
{
	int a[] = { 1, 5, 3, 7, 9, 8 };

	Heap hp;

	HeapInit(&hp, a, ARRSIZE(a));

	HeapPush(&hp, 10);
	HeapPop(&hp);//É¾³ý¶Ñ¶¥ÔªËØ
	HeapPrint(&hp);
	system("pause");
	return 0;
}