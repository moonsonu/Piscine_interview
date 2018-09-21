/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   findPotentialCriminels.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksonu <ksonu@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 19:17:32 by ksonu             #+#    #+#             */
/*   Updated: 2018/09/20 21:14:11 by ksonu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdlib.h>
#include <stdio.h>

#define MAX 1867111
#define NUM 10

void	countSort(struct s_criminal **c, int exp, int n)
{
	struct s_criminal	*r[n];
	int					arr[NUM] = {0};
	int					i;

	i = 0;
	for (i = 0; i < n; i++)
		arr[(c[i]->description / exp) % 10]++;
	for(i = 1; i < NUM; i++)
		arr[i] += arr[i - 1];
	for(i = n - 1; i >= 0; i--)
	{
		r[arr[(c[i]->description / exp) % 10] - 1] = c[i];
		arr[(c[i]->description / exp) % 10]--;
	}
	for (i = 0; i < n; i++)
		c[i] = r[i];
}

int getDescription(struct s_info *info)
{
	if (!info)
		return 0;
	return (info->gender * 1000000 +
		info->height * 100000 +
		info->hairColor * 10000 +
		info->eyeColor * 1000 +
		info->glasses * 100 +
		info->tattoo * 10 +
		info->piercing * 1);
}

void sortCriminals(struct s_criminal **criminals)
{
	int		x;
	int		i;
	int		size;

	i = 0;
	size = 0;
	while (criminals[i++])
		size += 1;
	for(x = 1; (MAX / x) > 0; x *= 10)
		countSort(criminals, x, size);
}

int					binarySearch(struct s_criminal **c, int l, int r, int d)
{
	int		m;

	m = (l + r) / 2;
	if (r >= l)
	{
		if (c[m]->description == d)
			return (m);
		if (c[m]->description > d)
			return (binarySearch(c, 1, m - 1, d));
		return (binarySearch(c, m + 1, r, d));
	}
	return (-1);
}

struct s_criminal	**findPotentialCriminals(struct s_criminal **criminals,
		struct s_info *info)
{
	int		i;
	int		size;
	int		d;
	int		b;
	int		l;
	int		r;
	struct s_criminal	**c;

	i = 0;
	size = 0;
	c = NULL;
	while (criminals[i++])
		size += 1;
	d = getDescription(info);
	b = binarySearch(criminals, 0, size - 1, d);
	if (b > 0)
	{
		l = b;
		r = b;
		while (l - 1 >= 0 && criminals[l - 1]->description == d)
			l--;
		while (r + 1 < size && criminals[r + 1]->description == d)
			r++;
		c = malloc(sizeof(struct s_criminal*) * (r - l + 2));
		for (i = 0; i <= r - l; i++)
			c[i] = criminals[l + i];
		c[i] = NULL;
	}
	return (c);
}
