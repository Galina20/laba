#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h> 

void increment(int *n);

void incrementStackVariable()
{
	int x = 0;
	printf("x = "); scanf("%x", &x);
	printf("%p = %d\n", &x, x);
	increment(&x);
	printf("%p = %d\n", &x, x);
}