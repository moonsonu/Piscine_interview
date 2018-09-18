/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searchPriceV2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksonu <ksonu@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 16:40:55 by ksonu             #+#    #+#             */
/*   Updated: 2018/09/17 17:12:00 by ksonu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <string.h>
#include <stdio.h>

int		searchPrice(struct s_art **arts, int n, char *name)
{
	int		start;
	int		end;
	int		mid;

	start = 0;
	end = n - 1;
	while (start <= end)
	{
		mid = (start + end) / 2;
		if (!strcmp(name, arts[mid]->name))
			return (arts[mid]->price);
		(strcmp(name, arts[mid]->name) < 0) ? (end = mid - 1) : (start = mid + 1);
	}
	return (-1);
}
