#include <iostream>
#define _USE_MATH_DEFINES
#include "Header.h"
#include <math.h>

int main() {
	Complex a = Complex(1, M_PI_2);
	Complex z = Complex::sinComplex(a);
	printf("%f  %f\n", z.Re(), z.Im());
	system("pause");
	return 0;
}