
#include <math.h>
int findFirstElement(double eps)
{
	double z;
	int i;
	for ( i = 0; ; i++) {
		z = pow(-1., i) * 1 / ((i + 1)*(i + 2)*(i + 3));
		if (fabs(z) <= eps) break;
	}
	return i;
}