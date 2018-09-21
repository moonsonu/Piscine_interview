/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quickSort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksonu <ksonu@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 02:05:03 by ksonu             #+#    #+#             */
/*   Updated: 2018/09/20 20:53:07 by ksonu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <string.h>
#include <stdio.h>

int		partition(struct s_player **players, int left, int right)
{
	int				i;
	int				j;
	struct s_player	*tmp;
	struct s_player	*pivot;

	i = left - 1;
	j = left;
	pivot = players[right];
	while (j <= right - 1)
	{
		if (players[j]->score >= pivot->score)
		{
			tmp = players[++i];
			players[i] = players[j];
			players[j] = tmp;
		}
		j++;
	}
	tmp = players[i + 1];
	players[i + 1] = players[right];
	players[right] = tmp;
	return (i + 1);
}

void	quick_sort(struct s_player **players, int left, int right)
{
	int		p;

	if (left < right)
	{
		p = partition(players, left, right);
		quick_sort(players, left, p - 1);
		quick_sort(players, p + 1, right);
	}
}

void	quickSort(struct s_player **players)
{
	int		i;
	int		size;

	i = -1;
	size = 0;
	while (players[++i])
		size += 1;
	quick_sort(players, 0, size - 1);
	
}
