#include "stack.h"
#include "Btree.h"


void StackInit(Stack *ps,size_t capacity)
{
	ps->a = (STDataType *) calloc (capacity, sizeof(STDataType));
	ps->top = 0;
	ps->capacity = capacity;
}
void StackDestory(Stack *ps)
{
	if (ps->a)
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
	if (ps->top == 0)
	{
		return;
	}
	ps->top--;
}
STDataType StackTop(Stack *ps)
{
	if (ps->top == 0)
	{
		return (STDataType)0;
	}
		return ps->a[ps->top - 1];
	
}


int StackEmpty(Stack *ps)
{
	return ps->top != 0;
}


int StackSize(Stack *ps)
{
	return ps->top;
}
