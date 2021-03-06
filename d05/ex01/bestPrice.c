/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bestPrice.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksonu <ksonu@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 22:11:11 by ksonu             #+#    #+#             */
/*   Updated: 2018/09/26 10:57:25 by ksonu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>
#define MAX(a, b) ((a > b) ? a : b)

void	recurse(double current, double *best, double *price, int n)
{
	if (n == 0) {
		*best = MAX(current, *best);
		return ;
	} for (int i = 1; i <= n; i++)
			recurse(current + price[i], best, price, n - i);
}

double	bestPrice(int pizzaSize, double *prices)
{
	double	best;

	recurse(0, &best, prices, pizzaSize);
	return (best);
}
