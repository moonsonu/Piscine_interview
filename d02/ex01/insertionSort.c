/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertionSort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksonu <ksonu@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 01:11:58 by ksonu             #+#    #+#             */
/*   Updated: 2018/09/20 02:03:23 by ksonu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>

void	insertionSort(struct s_player **players)
{
	int				i;
	int				j;
	struct s_player	*p;

	i = 0;
	while (players[++i] != NULL)
	{
		p = players[i];
		j = i;
		while (--j >= 0 && players[j]->score < p->score)
			players[j + 1] = players[j];
		players[j + 1] = p;
	}
}
