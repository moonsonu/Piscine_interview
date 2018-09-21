/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   countSort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksonu <ksonu@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 04:17:55 by ksonu             #+#    #+#             */
/*   Updated: 2018/09/20 18:40:58 by ksonu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void	countSort(unsigned char *utensils, int n)
{
	unsigned char	*r;
	int				arr[NUM] = {0};
	int				i;
	int				j;

	i = 0;
	r = (unsigned char*)malloc(sizeof(unsigned char) * n);
	for (i = 0; i < n; i++)
		arr[utensils[i] - 1]++;
	for(i = 1; i < NUM; i++)
		arr[i] += arr[i - 1];
	for(i = 0; i < n; i++)
	{
		j = arr[utensils[i] - 1];
		r[j - 1] = utensils[i];
		arr[utensils[i] - 1]--;
	}
	for (i = 0; i < n; i++)
		utensils[i] = r[i];
}
