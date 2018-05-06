#include <math.h>

double summ(int n)
{
	double z=0;
	double sum = 0;
	int i = 0;
	while (i < n)
	{
		z = pow(-1., i) * 1 / ((i + 1)*(i + 2)*(i + 3));
		sum = sum + z;
		i++;
	}
	return sum;
}