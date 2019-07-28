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

void QueuePush(Queue *pq,QUDataType x);//���
void QueuePop(Queue *pq);//ͷɾ

QUDataType QueueFront(Queue *pq);
QUDataType QueueBack(Queue *pq);

int QueueEmpty(Queue *pq);//�п� 1->�ǿ� 0->��
int QueueSize(Queue *pq);


#endif /*_QUEUE_H_*/