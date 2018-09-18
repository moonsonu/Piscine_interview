#include "header.h"

#define d 256

static int		howManyJesus(char *bible, char *jesus)
{
	int	m;
	int	n;
	int	i;
	int	j;
	int	p = 0;
	int	t = 0;
	int	h = 1;
	int	q = 10;
	m = strlen(bible);
	n = strlen(jesus);

	for (i = 0; i < m - 1; i++)
		h = (h * d) % q;
	for (i = 0; i < m; i++)
	{
		p = ( d * p + bible[i]) % q;
		t = (d * t + jesus[i]) % q;
	}
	for (i = 0; i <= n - m; i++)
	{
		if (p == t)
		{
			for (j = 0; j < M; j++)
			{
				if (jesus[i + j] != bible[j])
					break;
			}
			if (j == m)
				return (i);
		}
		if (i < (n - m))
		{
			t = (d * (t - jesus[i] * h) + jesus[i + m]) % q;
			if (t < 0)
				t = (t + q);
		}
	}
}
