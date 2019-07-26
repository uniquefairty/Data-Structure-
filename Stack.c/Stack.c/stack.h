#ifndef _STACK_H
#define _STACK_H

#include<stdio.h>
#include<Windows.h>
#include<stdlib.h>

#define N 10
typedef int STDataType;

//typedef struct Stack
//{
//	STDataType a[N];
//	int top;//ջ��
//}; //*******��̬ջ�ṹ

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

int StackEmpty(Stack *ps);//1�Ƿǿ� 0�ǿ�

int StackSize(Stack *ps);

//********������ջʵ�ֶ���*********
void Fun(Stack *ps,Stack *ps2);

#endif/*_STACK_H*/