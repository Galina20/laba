
#include <math.h>
int findFirstNegativeElement(double eps)
{
	int i;
	double z;
	for (i = 0; ; i++) {
		z = pow(-1., i) * 1 / ((i + 1)*(i + 2)*(i + 3));
		if (fabs(z) <= eps && z < 0) return i;
	}
	return i;
}
