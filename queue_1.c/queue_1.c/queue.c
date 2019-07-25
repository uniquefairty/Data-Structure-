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

void QueuePush(Queue *pq, QUDataType x)//���
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
void QueuePop(Queue *pq)//ͷɾ
{
	QueueNode *tmp = pq->front;
	if (pq->front == NULL)
	{
		return;
	}
	pq->front=tmp->next;
	free(tmp);
}

//���ض���ǰ��ĵ�ֵ
QUDataType QueueFront(Queue *pq)
{
	if (pq->front == NULL)
	{
		printf("����Ϊ��\n");
		return;
	}
	return pq->front->data;
}
QUDataType QueueBack(Queue *pq)
{
	if (pq->front == NULL)
	{
		printf("����Ϊ��\n");
		return;
	}
	return pq->rear->data;
}

//�п�
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