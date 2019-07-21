#include "SeqList.h"

void SeqListInit(SeqList *psl,size_t capacity)
{
	psl->array = (SLDataType *)calloc(capacity, sizeof(SLDataType));
	psl->capacity = capacity;
	psl->size = 0;
}
void SeqListDestory(SeqList *psl)
{
	if (psl->array)//防止重复摧毁
	{
		free(psl->array);
		psl->array = NULL;
		psl->size = 0;
		psl->capacity = 0;
	}
}
void CheckCapacity(SeqList *psl)
{
	if (psl->size == psl->capacity)
	{
		psl->capacity *= 2;
		SLDataType *tmp = (SLDataType *)realloc(psl->array, psl->capacity*sizeof(SLDataType));
		//psl->array= (SLDataType *)realloc(psl->array, psl->capacity*sizeof(SLDataType));
		if (tmp != NULL)
		{
			psl->array = tmp;
		}
	}
}
void SeqListPushBack(SeqList *psl, SLDataType x)
{
	CheckCapacity(psl);
	psl->array[psl->size] = x;
	psl->size++;
}
void SeqListPopBack(SeqList *psl)
{
	psl->size--;
}

void SeqListPushFront(SeqList *psl,SLDataType x)
{
	int i = 0;
	CheckCapacity(psl);

	for (i = psl->size-1; i >= 0; i--)
	{
		psl->array[i+1] = psl->array[i];
	}
	psl->array[i+1] = x;
	psl->size++;
}
void SeqListPopFront(SeqList *psl)
{
	int i = 0;
	for (i = 0; i <psl->size; i++)
	{
		psl->array[i] = psl->array[i+1];
	}
	psl->size--;
}
int SeqListFind(SeqList *psl, SLDataType x)
{
	int i = 0;
	for (i = 0; i < psl->size; i++)
	{
		if (x == psl->array[i])
		{
			return i;
		}
	}
	return -1;
}
void SeqListInsert(SeqList *psl, size_t pos, SLDataType x)
{
	int i = 0;
	CheckCapacity(psl);
	for (i = psl ->size-1; i >= pos; i--)
	{
		psl->array[i + 1] = psl->array[i];
	}
	psl->array[pos] = x;
	psl->size++;
}
void SeqListErase(SeqList *psl, size_t pos)
{
	int i = 0;
	for (i = pos; i <psl->size-1; i++)
	{
		psl->array[i] = psl->array[i + 1];
	}
	psl->size--;
}
void SeqListRemove(SeqList *psl, SLDataType x)
{
	SeqListErase(&psl, SeqListFind(psl, x));
}
void SeqListModify(SeqList *psl, size_t pos, SLDataType x)
{
	psl->array[pos] = x;
}
void SeqListPrint(SeqList *psl)
{
	int i = 0;
	for (i = 0; i < psl->size; i++)
	{
		printf("%d ", psl->array[i]);
	}
	putchar('\n');
}
void SqListBubbleSort(SeqList *psl)
{
	int i = 0;
	int j = 0;
	SLDataType tmp = 0;
	for (i = 0; i < psl->size-1; i++)
	{
		for (j = 0; j < psl->size - 1 - i; j++)
		{
			if (psl->array[j] > psl->array[j+1])
			{
				tmp = psl->array[j];
				psl->array[j] = psl->array[j+1];
				psl->array[j+1] = tmp;
			}
		}
	}
}
int SeqListBinaryFind(SeqList *psl, SLDataType x)
{
	int start = 0;
	int end = psl->size-1;
	while (start <end)
	{
		int mid =( end+start) / 2;
		if (psl->array[mid] > x)
		{
			end = mid - 1;
		}
		else if (psl->array[mid] < x)
		{
			start = mid + 1;
		}
		else
		{
			return mid;
		}
	}
}
//************************************************************************
void SeqListRemoveAll(SeqList *psl, SLDataType x)//时间复杂度O（n）  空间复杂度O（n）
{
	SLDataType *tmp=(SLDataType *)calloc(psl->capacity,sizeof(SLDataType));
	int i = 0;
	int j = 0;
	if (tmp != NULL)
	{
		for (i = 0, j = 0; i < psl->size; i++)
		{
			if (psl->array[i] != x)
			{
				tmp[j] = psl->array[i];
				j++;
			}
		}
	}
	free(psl->array);
	psl->array = tmp;
	psl->size = j;
}
//**********************************************************************
void SeqListRemoveAll_1(SeqList *psl, SLDataType x)//时间复杂度O（n）  空间复杂度O（1）
{
	SLDataType *tmp;
	int i;
	int gap = 0;
	for (i = 0; i < psl->size; i++)
	{
		if (psl->array[i] == x)
		{
			gap++;
		}
		else
		{
			psl->array[i - gap] = psl->array[i];
		}
	}
	psl->size -= gap;
}
//********************************************************************
/*void SeqListRemoveAll_2(SeqList* psl, SLDataType x)
{
	int gap = 0;
	int i;
	for (i = 0; i < psl->size - gap; i++)
	{
		if (psl->array[i + gap] == x)
		{
			if (psl->array[i + gap] == psl->array[i + gap + 1])
			{
				i--;
				gap++;
				continue;
			}
			gap++;
			if (i + gap >= psl->capacity)
			{
				break;
			}
		}
		psl->array[i] = psl->array[i + gap];
	}
	psl->size -= gap;
}
*/