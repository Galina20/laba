#include <math.h>
int findFirstElement(double eps)
{
	double z;
	int i=0;
	while (1)
	{
		z = pow(-1., i) * 1 / ((i + 1)*(i + 2)*(i + 3));
		if (fabs(z) <= eps) break;
		i++;
	}
	return i;
}