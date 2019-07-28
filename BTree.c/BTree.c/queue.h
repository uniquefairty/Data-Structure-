#ifndef _QUEUE_H_
#define _QUEUE_H_

#include<stdio.h>
#include<Windows.h>
#include "Btree.h"

typedef BTNode * QUDataType;

typedef struct QueueNode
{
	struct QueueNode *next;
	QUDataType data;
}QueueNode;

typedef struct Queue
{
	QueueNode *front;
	QueueNode *rear;
}Queue;

void QueueInit(Queue *pq);
void QueueDestory(Queue *pq);

void QueuePush(Queue *pq,QUDataType x);//╨С╡Е
void QueuePop(Queue *pq);//м╥и╬

QUDataType QueueFront(Queue *pq);
QUDataType QueueBack(Queue *pq);

int QueueEmpty(Queue *pq);//еп©у 1->╥г©у 0->©у
int QueueSize(Queue *pq);


#endif /*_QUEUE_H_*/