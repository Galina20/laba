#include <math.h>

double summ(int n)
{
	double z;
	double sum = 0;
	for (int i = 0; i < n; i++)
	{
		z = pow(-1., i) * 1 / ((i + 1)*(i + 2)*(i + 3));
		sum = sum + z;
	}
	return sum;
}