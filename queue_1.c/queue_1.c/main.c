#include "queue.h"


int main()
{
	Queue pq;
	QueueInit(&pq);

	QueuePush(&pq, 4);
	QueuePush(&pq, 8);
	QueuePush(&pq, 9);

	QueuePop(&pq);

	printf("%d ", QueueFront(&pq));
	printf("%d \n", QueueBack(&pq));

	printf("%d",QueueSize(&pq));
	QueueDestory(&pq);
	


	system("pause");
	return 0;
}