#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 

void writeArray(int *arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
}