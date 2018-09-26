#include "header.h"
#define MAX(a, b) ((a > b) ? a : b)

double	recurse(double best, double *price, int n)
{
	double		current = 0.0;

	if (n == 0)
		return (best);
	for (int i = n;  i >= 0; i--)
	{
		for (int j = n - 1; j > 0; j--)
			current += price[i];
	}
	return (recurse(MAX(current, best), price, n - 1));
}

double	bestPrice(int pizzaSize, double *prices)
{
	double	best;

	best = recurse(0, prices, pizzaSize);
	return (best);
}
