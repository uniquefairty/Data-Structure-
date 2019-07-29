#include "Heap.h"

void Swap(HPDataType *a, HPDataType *b)
{
	HPDataType tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}
void DownAdjust(Heap *hp, int n)//堆向下调整法
{
	int cur = n;
	while (cur*2+1<hp->_size)//如果一个堆的节点没有左节点，那么它就是叶子，直接跳出
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

void HeapInit(Heap *hp, HPDataType *a, HPDataType n)//数组不是堆，调整为堆
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

void HeapPush(Heap *hp, HPDataType x)//比根大就交换
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

void HeapPop(Heap *hp)//最后一个元素和堆顶交换，然后删除数组最后一个数据，在进行向下调整法
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

// 堆排序
void HeapSort(Heap *hp)
{
	int cur = hp->_size;

	while (hp->_size>=1)
	{
		HeapPop(hp);
	}
	hp->_size = cur;

}
