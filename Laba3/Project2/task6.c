#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

double summ(int n);
double summ2(double eps);
void print(int n, int k);
int findFirstElement(double eps);
int findFirstNegativeElement(double eps);

int main()
{
	setlocale(LC_ALL, "Rus");
	char answer;
	do
	{
		printf("1. ������� 1\n\r");
		printf("2. ������� 2\n\r");
		printf("3. ������� 3\n\r");
		printf("4. ������� 4\n\r");
		printf("5. ������� 5\n\r");
		printf("6. �����\n\r");
		printf("�����: ");
		answer = getchar();
		system("cls");
		switch (answer)
		{
		case '1':
		{
			int n = 0;
			printf("������� n: "); scanf("%d", &n);
			printf("���������: %lf\n", summ(n));
			break;
		}
		case '2':
		{
			double e = 0;
			printf("������� e: "); scanf("%lf", &e);
			printf("���������: %lf\n", summ2(e));
			break;
		}
		case '3':
		{
			int n = 0, k = 0;
			printf("������� n: "); scanf("%d", &n);
			printf("������� k: "); scanf("%d", &k);
			print(n, k);
			break;
		}
		case '4':
		{
			double e = 0;
			printf("������� �: "); scanf("%lf", &e);
			printf("���������: %d\n", findFirstElement(e));
			break;
		}
		case '5':
		{
			double e = 0;
			printf("������� e: "); scanf("%lf", &e);
			printf("���������: %d\n", findFirstNegativeElement(e));
			break;
		}
		case '6':
			break;
		default:
			printf("�������� ����!\n\r");
			break;
		}
		system("pause"); system("cls");
	} while (answer != '6');
	return 0;
}