#include <math.h>
int findFirstNegativeElement(double eps)
{
	int i=0;
	double z;
	while (1)
	{
		z = pow(-1., i) * 1 / ((i + 1)*(i + 2)*(i + 3));
		if (fabs(z) <= eps && z < 0) return i;
		i++;
	}
	return i;
}