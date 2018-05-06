#include <math.h>
#include <stdio.h>

void print(int n, int k)
{
	for (int i = 0; i < n; i++)
	{
		if ((i + 1) % k == 0) continue;
		else
		{
			double z = pow(-1., i) * 1 / ((i + 1)*(i + 2)*(i + 3));
			printf("%lf ", z);
		}
	}
}