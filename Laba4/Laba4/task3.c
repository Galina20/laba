#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>

void increment(int *n);

void incrementHeapVariable()
{
	int *x = (int *)malloc(sizeof(int));
	printf("x = "); scanf("%d", x);
	printf("%p = %d\n", x, *x);
	increment(x);
	printf("%p = %d\n", x, *x);
	free(x);
}