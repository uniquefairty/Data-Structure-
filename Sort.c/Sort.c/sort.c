#include "sort.h"

void dealMergeSort(int *arr, int *tmp, int start, int end)
{
	if (start >= end)//�ݹ���� ����Ҷ��
	{
		return;
	}
	int mid = (start + end) / 2;//����������
	dealMergeSort(arr, tmp, start, mid);//����������
	dealMergeSort(arr, tmp, mid+1, end);//����������

	//��ʵ��һ���������ĺ������

	int a=start;
	int b=mid+1;
	int c = a;

	for (; a <= mid&&b <= end; c++)//��a��b����һ����Ԫ���Ѿ���ȫ������c��ʱ��ѭ������
	{
		if (arr[a] <= arr[b])
		{
			tmp[c] = arr[a];
			a++;
		}
		else
		{
			tmp[c] = arr[b];
			b++;
		}
	}

	for (; a <= mid; a++, c++)//�����������b����ô��aʣ�µĿ�����c��
	{
		tmp[c] = arr[a];
	}

	for (; b <= end; b++, c++)//����������ǣ���ô��bʣ�µĿ�����c��
	{
		tmp[c] = arr[a];
	}

	int i;
	for (i = start; i <= end; i++)//a��b��������һ�����飬����ԭ���飬c����ʱ�ռ䣬����c��ֵ������ԭ����
	{
		arr[i] = tmp[i];
	}
}
void mergeSort(int *arr, int n)//����ӿڣ���arr��n��
{
	int *tmp = (int *)malloc(n*sizeof(int));
	dealMergeSort(arr, tmp, 0, n-1);

	free(tmp);
}

void SwapArgs(int *a, int *b)
{
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}
void dealQSort(int *arr, int start, int end)//startָ�������Ϊ���εĻ�׼ֵ
{
	int flag = 1;

	if (start >= end)
	{
		return;
	}

	int i = start, j = end;
	while (i < j)
	{
		if (arr[i]>arr[j])
		{
			SwapArgs(arr + i, arr + j);
			flag = !flag;
		}

		flag ? j-- : i++;//������ʱflagΪ1������ָ�붯������flagΪ2��ǰ��ָ�붯
	}

	dealQSort(arr,start, i-1);
	dealQSort(arr,i+1,end);
}

void Qsort(int *arr, int n)//��������
{
	dealQSort(arr, 0, n-1);
}
