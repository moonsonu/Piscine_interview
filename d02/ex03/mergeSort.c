/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mergeSort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksonu <ksonu@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 02:58:45 by ksonu             #+#    #+#             */
/*   Updated: 2018/09/20 04:15:47 by ksonu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void				merge(struct s_player **player, int l, int m, int r)
{
	int		i;
	int		j;
	int		k;
	int		z;
	struct	s_player	*tmp;

	i = l;
	j = m + 1;
	k = l;

	tmp = player[i];
	while (i <= m && j <= r)
	{
		if (player[i]->score <= player[j]->score)
			tmp[k++] = *player[i++];
		else
			tmp[k++] = *player[j++];
	}
	if (i < m)
	{
		for (l = j; l <= r; l++)
			tmp[k++] = *player[l];
	}
	else
	{
		for(l = i; l <= m; l++)
			tmp[k++] = *player[l];
	}
	for (z = l; z <= r; z++)
		player[z] = &tmp[z];
}

void				divide(struct s_player **player, int l, int r)
{
	int		m;

	if (r > l)
	{
		m = (l + r) / 2;
		divide(player, l, m);
		divide(player, m + 1, r);
		merge(player, l, m, r);
	}
}

struct s_player		**mergeSort(struct s_player **players)
{
	int		i;
	int		size;

	i = -1;
	size = 0;
	while (players[++i])
		size += 1;
	divide(players, 0, size - 1);
	return (players);
}
