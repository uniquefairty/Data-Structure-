#include "queue.h"

void QueueInit(Queue *pq)
{
	pq->front=NULL;
	pq->rear= NULL;
}

void QueueDestory(Queue *pq)
{
	if (pq->front == NULL)
	{
	return;
    }
	while (pq->front)
	{
		QueuePop(pq);
	}
}

void QueuePush(Queue *pq, QUDataType x)//后插
{
	QueueNode *tmp = (QueueNode *)malloc(sizeof(QueueNode));
	tmp->data = x;
	tmp->next = NULL;
	
	if (pq->front ==NULL)
	{
		pq->front=pq->rear = tmp;
		return;
	}
	pq->rear->next = tmp;
	pq->rear = tmp;
}
void QueuePop(Queue *pq)//头删
{
	QueueNode *tmp = pq->front;
	if (pq->front == NULL)
	{
		return;
	}
	pq->front=tmp->next;
	free(tmp);
}

//返回队列前面的的值
QUDataType QueueFront(Queue *pq)
{
	if (pq->front == NULL)
	{
		printf("队列为空\n");
		return;
	}
	return pq->front->data;
}
QUDataType QueueBack(Queue *pq)
{
	if (pq->front == NULL)
	{
		printf("队列为空\n");
		return;
	}
	return pq->rear->data;
}

//判空
int QueueEmpty(Queue *pq)
{
	return pq->front == NULL;
}


int QueueSize(Queue *pq)
{
	/*if (pq->front == NULL)
	{
		return 0;
	}
	return (pq->rear - pq->front)+1 ;*///ERROR

	QueueNode *cur;
	int size=0;
	for (cur = pq->front; cur!=NULL; cur = cur->next)
	{
		size++;
	}
	return size;
}