#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void increment(int *n);
void incrementStackVariable();
void incrementHeapVariable();
void writeArray(int *arr, int n);
void readArray(int *arr, int n);
void sort(int *arr, int n);
void sortStackArray();
void sortHeapArray();

int main()
{
	setlocale(LC_ALL, "Rus");
	while (1)
	{
		printf("1. Задание 2 (Число в стеке)\n");
		printf("2. Задание 3 (Число в дин.памяти)\n");
		printf("3. Задание 7 (Массив из N в стеке)\n");
		printf("4. Задание 8 (Массив из N в дин.памяти)\n");
		printf("5. Выход\n");
		printf("Выбор: ");

		switch (getchar())
		{
		case '1':
		{
			printf("=== Число в стеке ===\n");
			incrementStackVariable();
			break;
		}
		case '2':
		{
			printf("=== Число в дин.памяти ===\n");
			incrementHeapVariable();
			break;
		}
		case '3':
		{
			printf("=== Массив из N в стеке ===\n");
			sortStackArray();
			break;
		}
		case '4':
		{
			printf("=== Массив из N в дин.памяти ===\n");
			sortHeapArray();
			break;
		}
		case '5':
			return 0;
		default:
			printf("Неверный ввод!\n");
			break;
		}
		system("pause"); system("cls");
	}
	return 0;
}