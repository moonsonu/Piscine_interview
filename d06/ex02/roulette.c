/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   roulette.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksonu <ksonu@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 11:14:21 by ksonu             #+#    #+#             */
/*   Updated: 2018/09/27 13:05:54 by ksonu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>

double		winning(double init, double want, int n, double p)
{
	double	r = 0;
	double	b = 0;
	double	g = 0;
	if (n == 0 && init >= want)
		return (p);
	if (init >= want)
		return (p);
	for (int i = n; i >= 0; i--)
	{
		r = winning(init * 2, want, n - 1, p * ((double)18 / (double)37));
		b = winning(0, want, n - 1, p * ((double)18 / (double)37));
		g = winning(init / 2, want, n - 1, p * ((double)1 / (double)37));
		printf("r[%f] b[%f] g[%f]\n", r, b, g);
	}
	p = r + b + g;
	return (p);
}

double	probabilityWin(double initDollars, double wantedDollars, int nbGame)
{
	int		p = 1;

	return (winning(initDollars, wantedDollars, nbGame, p));
}
