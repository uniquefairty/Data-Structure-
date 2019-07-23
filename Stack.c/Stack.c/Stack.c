#include "stack.h"


void StackInit(Stack *ps,size_t capacity)
{
	ps->a = (STDataType *) calloc (capacity, sizeof(STDataType));
	ps->top = 0;
	ps->capacity = capacity;
}
void StackDestory(Stack *ps)
{
	if (ps->capacity)
	{
		free(ps->a);
		ps->a = NULL;
		ps->top = 0;
		ps->capacity = 0;

	}
}
void CheckCapacity(Stack *ps)
{
	if (ps->top == ps->capacity)
	{
		ps->capacity *= 2;
		STDataType *tmp = (STDataType *)realloc(ps->a, ps->capacity*sizeof(STDataType));
		if (tmp != NULL)
		{
			ps->a = tmp;
		}
	}
}
void StackPush(Stack *ps, STDataType x)
{
	CheckCapacity(ps);
	ps->a[ps->top] = x;
	ps->top++;
}
void StackPop(Stack *ps)
{
	ps->top--;
}
STDataType StackTop(Stack *ps)
{
	return ps->a[ps->top-1];
}
int StackSize(Stack *ps)
{
	return ps->top;
}

//********用栈实现队列*********
void Fun(Stack *ps, Stack *ps2)
{
	while (ps->top != 0)
	{
		while (ps->top != 1)
		{
			CheckCapacity(ps2);
			ps2->a[ps2->top] = ps->a[ps->top - 1];
			ps->top--;
			ps2->top++;
		}
		printf("%d\n", ps->a[--ps->top]);
		while (ps2->top !=0)
		{
			ps->a[ps->top] = ps2->a[ps2->top - 1];
			ps->top++;
			ps2->top--;
		}
	}
}