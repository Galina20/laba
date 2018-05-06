#include <math.h>
#include <stdio.h>

void print(int n, int k)
{
	int i = 0;
	while (i < n)
	{
		if ((i + 1) % k == 0)
		{
			++i;
			continue;
		}
		else
		{
			double z = pow(-1., i) * 1 / ((i + 1)*(i + 2)*(i + 3));
			printf("%lf ", z);
			i++;
		}
	}
}