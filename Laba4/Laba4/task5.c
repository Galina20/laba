#include <stdio.h> 

void readArray(int *arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("Элемент №%d: ", i + 1); scanf_s("%d", &arr[i]);
	}
}