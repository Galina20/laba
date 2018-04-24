
#include <stdio.h> 
#include <math.h> 
double PI = 3.14;

double f(float x);

int main()
{
	float x = 2;
	printf("x = %.0f\n", x);
	printf("f(x) = %.4f\n", f(x));

	printf("x = ");
	scanf_s("%f", &x);
	printf("f(x) = %.4f\n", f(x));

	return 0;
}

double f(float x)
{
	return (2 * sin(PI*x - 2 * x)*sin(PI*x - 2 * x)*cos(PI * 5 + 5 * x)*cos(PI * 5 + 5 * x));
}
