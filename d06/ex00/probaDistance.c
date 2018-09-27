/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   probaDistance.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksonu <ksonu@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 11:10:26 by ksonu             #+#    #+#             */
/*   Updated: 2018/09/27 11:11:40 by ksonu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>
double probaDistance(int dist, int *locations, int n)
{
	int		p = 0;
	int		total = (n * (n - 1)) / 2;
	for (int i = 0; i < n; i++)
	{
		for (int j = 1; j < n; j++)
		{
			if (locations[j] - locations[i] > dist)
				p++;
		}
	}
	return ((double)p / (double)total);
}
