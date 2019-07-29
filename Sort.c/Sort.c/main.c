#include "sort.h"

void arryPrint(int *a,int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	putchar('\n');
}
int main()
{
	int a[] = { 10,6,7,1,3,9,4,2 };
	//mergeSort(a, ARRSIZE);
	Qsort(a, ARRSIZE);
	arryPrint(a,ARRSIZE);

	system("pause");
	return 0;
}