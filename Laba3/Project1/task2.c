#include <math.h>

double summ2(double e)
{
	double z = pow(-1., 0) * 1 / (1 * 2 * 3);
	if (fabs(z) < e) return z;
	double sum = z;
	for (int i = 1; fabs(z) > e; i++)
	{
		z = pow(-1., i) * 1 / ((i + 1)*(i + 2)*(i + 3));
		sum += z;
	}
	return sum;
}