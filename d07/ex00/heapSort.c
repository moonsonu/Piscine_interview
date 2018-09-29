/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heapSort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksonu <ksonu@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/28 11:15:44 by ksonu             #+#    #+#             */
/*   Updated: 2018/09/28 12:47:53 by ksonu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <string.h>
#include <stdio.h>

void	swap(struct s_art **masterpiece, int i, int max)
{
	struct s_art	*tmp;

	tmp = masterpiece[max];
	masterpiece[max] = masterpiece[i];
	masterpiece[i] = tmp;
}

void	heapify(struct s_art **masterpiece, int n, int i)
{
		int		left = 2 * i + 1;
		int		right = 2 * i + 2;
		int		max = i;
		if (left < n  && strcmp(masterpiece[left]->name,
					masterpiece[max]->name) > 0)
			max = left;
		if (right < n && strcmp(masterpiece[right]->name,
					masterpiece[max]->name) > 0)
				max = right;
		if (max != i)
		{
			swap(masterpiece, i, max);
			heapify(masterpiece, n, max);
		}
}

void		heapSort(struct s_art **masterpiece, int n)
{
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(masterpiece, n, i);
	for (int i = n -1; i >= 0; i--)
	{
		swap(masterpiece, i, 0);
		heapify(masterpiece, i, 0);
	}
}
