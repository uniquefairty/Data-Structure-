#ifndef _QUEUE_H_
#define _QUEUE_H_


#include<stdio.h>
#include<windows.h>

#define QueueMAX 4

typedef int QUDataType;

typedef struct Queue
{
	QUDataType data[QueueMAX];
	QUDataType *front;
	QUDataType *rear;
	size_t size;
}Queue;

void QueueInit(Queue *pq);
void QueueDestory(Queue *pq);

void QueuePush(Queue *pq, QUDataType x);//ºó²å
void QueuePop(Queue *pq);//Ç°É¾

QUDataType QueueFront(Queue *pq);
QUDataType QueueBack(Queue *pq);



#endif /*_QUEUE_H_*/