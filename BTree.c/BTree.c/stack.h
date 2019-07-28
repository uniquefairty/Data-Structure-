#ifndef _STACK_H
#define _STACK_H

#include<stdio.h>
#include<Windows.h>
#include<stdlib.h>

#include "Btree.h"
#define N 10
typedef BTNode * STDataType;

//typedef struct Stack
//{
//	STDataType a[N];
//	int top;//栈顶
//}; //*******静态栈结构

typedef struct Stack
{
	STDataType *a;
	int top;
	int capacity;
}Stack;

void StackInit(Stack *ps,size_t capacity);
void StackDestory(Stack *ps);

void CheckCapacity(Stack *ps);

void StackPush(Stack *ps, STDataType x);
void StackPop(Stack *ps);

STDataType StackTop(Stack *ps);

int StackEmpty(Stack *ps);//1是非空 0是空

int StackSize(Stack *ps);


#endif/*_STACK_H*/