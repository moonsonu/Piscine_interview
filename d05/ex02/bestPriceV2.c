/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bestPriceV2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksonu <ksonu@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 00:00:40 by ksonu             #+#    #+#             */
/*   Updated: 2018/09/26 11:56:44 by ksonu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdlib.h>
#define MAX(a, b) (a > b ? a : b)
double	recurse(int n, double *price, double *tmp)
{
	double	best = price[n];
	if (tmp[n])
		return (tmp[n]);
	else
		for (int i = 1; i < n; i++)
			best = MAX(best, recurse(n - i, price, tmp) + recurse(i, price, tmp));
	tmp[n] = best;
	return (best);
}

double	optimizedBestPrice(int pizzaSize, double *prices)
{
	double	*best = (double*)malloc(sizeof(double));
	for (int i = 0; i < pizzaSize + 1; i++)
		best[i] = 0;
	return (recurse(pizzaSize, prices, best));
}
