#include "Heap.h"

void Swap(HPDataType *a, HPDataType *b)
{
	HPDataType tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}
void DownAdjust(Heap *hp, int n)//�����µ�����
{
	int cur = n;
	while (cur*2+1<hp->_size)//���һ���ѵĽڵ�û����ڵ㣬��ô������Ҷ�ӣ�ֱ������
	{
		if ((hp->_data[cur] < hp->_data[cur * 2 + 1]))
		{
			if (cur * 2 + 2> hp->_size || hp->_data[cur * 2 + 2] <= hp->_data[cur * 2 + 1])
			{
				Swap(&hp->_data[cur], &hp->_data[cur * 2 + 1]);
				cur = cur * 2 + 1;
			}
			else
			{
				Swap(&hp->_data[cur], &hp->_data[cur * 2 + 2]);
				cur = cur * 2 + 2;
			}
		}
		else if (cur * 2 + 2< hp->_size && hp->_data[cur] < hp->_data[cur * 2 + 2])
        {
        	Swap(&hp->_data[cur], &hp->_data[cur * 2 + 2]);
        	cur = cur * 2 + 2;
        
        }
        else
        {
        	break;
        }
	}
}

void HeapInit(Heap *hp, HPDataType *a, HPDataType n)//���鲻�Ƕѣ�����Ϊ��
{
	int i;
	hp->_capacity = MAXSIZE>n?MAXSIZE:n;
	hp->_size = n;
	hp->_data = (HPDataType *)malloc(sizeof(HPDataType)*hp->_capacity);
	memcpy(hp->_data, a, sizeof(HPDataType)*n);
	
	for (i = n/2 - 1; i >= 0; i--)
	{
		DownAdjust(hp, i);
	}

}

void HeapDestory(Heap *hp)
{
	if (hp->_data)
	{
		free(hp->_data);
		hp->_data = NULL;
		hp->_capacity = 0;
	}
}

void HeapPush(Heap *hp, HPDataType x)//�ȸ���ͽ���
{
	int cur = hp->_size;
	if (hp->_size == hp->_capacity)
	{
		hp->_capacity *= 2;
	    hp->_data = (HPDataType *)realloc(hp->_data, sizeof(HPDataType)*hp->_capacity);
	}

	hp->_data[hp->_size] = x;
	hp->_size++;
	
	while (cur)
	{
		if (hp->_data[cur] > hp->_data[(cur - 1) / 2])
		{
			Swap(&hp->_data[cur], &hp->_data[(cur - 1) / 2]);
			cur = (cur - 1) / 2;
		}
		else
		{
			break;
		}
	}
}

void HeapPop(Heap *hp)//���һ��Ԫ�غͶѶ�������Ȼ��ɾ���������һ�����ݣ��ڽ������µ�����
{
	Swap(&hp->_data[hp->_size-1], &hp->_data[0]);
	hp->_size--;
	DownAdjust(hp, 0);
}


HPDataType HeapTop(Heap *hp)
{
	return hp->_data[hp->_size - 1];
}

int _HeapSize(Heap *hp)
{
	return hp->_size;
}
int HeapEmpty(Heap *hp)
{
	return hp->_size == 0;
}
void HeapPrint(Heap *hp)
{
	int i = 0;
	int tmp=1;
	int flag=0;
	for (i=0;i<hp->_size; i++)
	{
		printf("%d ", hp->_data[i]);
		if (i == flag)
		{
			putchar('\n');
			tmp *= 2;
			flag += tmp;
		}
	}
}

// ������
void HeapSort(Heap *hp)
{
	int cur = hp->_size;

	while (hp->_size>=1)
	{
		HeapPop(hp);
	}
	hp->_size = cur;

}
