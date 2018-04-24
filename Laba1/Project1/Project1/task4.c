
#include <stdio.h> 
#include <math.h> 
double PI = 3.14;
float x, result;
void f();
int main()
{
	x = 2;
	printf("x = %.0f\n", x);
	f();
	printf("f(x) = %.4f\n", result);

	printf("x = ");
	scanf_s("%f", &x);
	f();
	printf("f(x) = %.4f\n", result);

	return 0;
}
void f()
{
	result = 2 * sin(PI*x - 2 * x)*sin(PI*x - 2 * x)*cos(PI * 5 + 5 * x)*cos(PI * 5 + 5 * x);

}

