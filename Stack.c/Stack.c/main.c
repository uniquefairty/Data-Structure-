#include "stack.h"

int main()
{
	Stack ps;
	Stack ps2;
	StackInit(&ps, 1);
	StackInit(&ps2, 1);

	StackPush(&ps, 10);
	StackPush(&ps, 3);
	StackPush(&ps, 9);
	StackPush(&ps, 5);
	//StackPop(&ps);

	Fun(&ps,&ps2);
	//printf("%d\n", StackTop(&ps));
	//printf("%d\n", StackSize(&ps));

	StackDestory(&ps);
	StackDestory(&ps2);

	system("pause");
	return 0;
}
int main1()
{
	Stack ps;
	StackInit(&ps,1);

	StackPush(&ps, 10);
	StackPush(&ps, 3);
	StackPush(&ps, 9);
	StackPush(&ps, 5);
	StackPop(&ps);

	printf("%d\n",StackTop(&ps));
	printf("%d\n", StackSize(&ps));

	StackDestory(&ps);
	system("pause");
	return 0;
}