#include <math.h>

double summ(int n)
{
	double z = 0;
	double sum = 0;
	int i = 0;
	if (i >= n) return 0;
	do
	{
		z = pow(-1., i) * 1 / ((i + 1)*(i + 2)*(i + 3));
		sum = sum + z;
		i++;
	} while (i < n);
	return sum;
}