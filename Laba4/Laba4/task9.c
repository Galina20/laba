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
		printf("1. ������� 2 (����� � �����)\n");
		printf("2. ������� 3 (����� � ���.������)\n");
		printf("3. ������� 7 (������ �� N � �����)\n");
		printf("4. ������� 8 (������ �� N � ���.������)\n");
		printf("5. �����\n");
		printf("�����: ");

		switch (getchar())
		{
		case '1':
		{
			printf("=== ����� � ����� ===\n");
			incrementStackVariable();
			break;
		}
		case '2':
		{
			printf("=== ����� � ���.������ ===\n");
			incrementHeapVariable();
			break;
		}
		case '3':
		{
			printf("=== ������ �� N � ����� ===\n");
			sortStackArray();
			break;
		}
		case '4':
		{
			printf("=== ������ �� N � ���.������ ===\n");
			sortHeapArray();
			break;
		}
		case '5':
			return 0;
		default:
			printf("�������� ����!\n");
			break;
		}
		system("pause"); system("cls");
	}
	return 0;
}