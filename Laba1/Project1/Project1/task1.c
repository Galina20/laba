#include <stdio.h> 
#include <math.h> 
double PI = 3.14;

int main()
{
	float x = 1;
	float z;

	//переменные заданы в виде констант 
	z = 2 * (sin(PI*x - 2 * x)*sin(PI*x - 2 * x))*(cos(PI * 5 + 5 * x)*cos(PI * 5 + 5 * x));
	printf("x=%f\n", x);
	printf("f(x)=%.4f\n", z);

	//переменные задаются с клавиатуры 
	printf("x=");
	scanf_s("%f", &x);
	z = 2 * (sin(PI*x - 2 * x)*sin(PI*x - 2 * x))*(cos(PI * 5 + 5 * x)*cos(PI * 5 + 5 * x));
	printf("f(x)=%.4f\n", z);

	return 0;
}
