/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortArts.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksonu <ksonu@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 11:51:27 by ksonu             #+#    #+#             */
/*   Updated: 2018/09/17 16:35:47 by ksonu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <string.h>
#include <stdio.h>

int		partition(struct s_art **arts, int left, int right)
{
	int				low;
	int				high;
	struct s_art	*tmp;
	char			*pivot;

	low = left + 1;
	high = right;
	pivot = arts[left]->name;
	
	while (low < high)
	{
		while (low <= right && (strcmp(arts[low]->name, pivot) < 0))
			low++;
		while (high >= left && (strcmp(arts[high]->name, pivot) > 0))
			high--;
		if (low < high)
		{
			tmp = arts[low];
			arts[low] = arts[high];
			arts[high] = tmp;
		}
	}
	tmp = arts[left];
	arts[left] = arts[high];
	arts[high] = tmp;
	return (high);
}

void	quick_sort(struct s_art **arts, int left, int right)
{
	int		p;

	if (left < right)
	{
		p = partition(arts, left, right);
		quick_sort(arts, left, p - 1);
		quick_sort(arts, p + 1, right);
	}
}

void	sortArts(struct s_art **arts)
{
	int		i;
	int		size;

	i = -1;
	size = 0;
	while (arts[++i])
		size += 1;
	quick_sort(arts, 0, size - 1);
}
