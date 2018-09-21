/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printYoungest.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksonu <ksonu@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 22:47:54 by ksonu             #+#    #+#             */
/*   Updated: 2018/09/20 22:51:28 by ksonu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>

void	sink(int *ages, int current, int end)
{
	int		lc;
	int		rc;
	int		max;
	int		tmp;

	lc = (current + 1) * 2 - 1;
	if (lc >end)
		return;
	rc = lc + 1;
	max = (rc > end) ? lc : (ages[lc] > ages[rc]) ? lc : rc;
	if (ages[current] > ages[max])
		return;
	tmp = ages[current];
	ages[current] = ages[max];
	ages[max] = tmp;
	sink(ages, max, end);
}
void	printYoungest(int *ages, int length)
{
	int		i;
	int		tmp;

	for (i = (length - 1) / 2; i >= 0; i--)
		sink(ages, i, length - 1);
	for (i = 0; i < length - 1; i++)
	{
		tmp = ages[0];
		ages[0] = ages[(length - 1) - i];
		ages[(length - 1) - i] = tmp;
		sink(ages, 0, (length - 1) - i - 1);
	}
	printf("Youngest : %d\n", ages[0]);
}
