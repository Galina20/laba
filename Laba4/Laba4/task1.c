#include <stdio.h>

void increment(int *n)
{
	if (!n) return;
	printf("%p = %d\n", n, *n);
	(*n)++;
	printf("%p = %d\n", n, *n);
}