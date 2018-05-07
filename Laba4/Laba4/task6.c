#include <stdlib.h>
#include <locale.h>
void sort(int *arr, int n)
{
	setlocale(LC_ALL, "Rus");
	//Вариант 1 - сортировка выбором
	for (int i = 0; i < n ; i++)
	{
		int min = i;
		for (int j = i + 1; j < n; j++)
		{
			if (arr[min] > arr[j]) 
				min = j;
		}
		if (min != i)
		{
			int tmp = arr[min];
			arr[min] = arr[i];
			arr[i] = tmp;
		}
	}
}