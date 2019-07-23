#include "queue.h"


void QueueInit(Queue *pq)
{
	pq->front = pq->data;
	pq->rear = pq->data;
	pq->size = 0;
}
void QueueDestory(Queue *pq)
{
	pq->front = pq->rear = pq->data;
	pq->size = 0;
}
void QueuePush(Queue *pq, QUDataType x)//ºó²å
{
	if (pq->size+1 == QueueMAX)
	{
		return;
	}

	*pq->rear = x;
	pq->rear++;
	pq->size++;

	if (pq->rear-pq->data==QueueMAX)
	{
		pq->rear = pq->data;
	}
}
void QueuePop(Queue *pq)//Ç°É¾
{
	if (pq->size==0)
	{
		return;
	}
	pq->front++;
	pq->size--;

	if (pq->front - pq->data == QueueMAX)
	{
		pq->front == pq->data;
	}
}
QUDataType QueueFront(Queue *pq)
{
	if (pq->size == 0)
	{
		return (QUDataType)-1;
	}
	return *pq->front;
}
QUDataType QueueBack(Queue *pq)
{
	if (pq->size==0)
	{
		return (QUDataType)-1;
	}
	if (pq->rear == pq->data)
	{
		return pq->data[QueueMAX - 1];
	}
	return  *(pq->rear - 1);
}