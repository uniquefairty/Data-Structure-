#ifndef _QUEUE_H_
#define _QUEUE_H_

#include<stdio.h>
#include<Windows.h>

typedef int QUDataType;

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

void QueuePush(Queue *pq,QUDataType x);//ºó²å
void QueuePop(Queue *pq);//Í·É¾

QUDataType QueueFront(Queue *pq);
QUDataType QueueBack(Queue *pq);

int QueueSize(Queue *pq);


#endif /*_QUEUE_H_*/