/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hotspots.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksonu <ksonu@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 11:12:17 by ksonu             #+#    #+#             */
/*   Updated: 2018/09/27 11:12:55 by ksonu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>
int		selectHotspots(struct s_hotspot **hotspots)
{
	int		count = 1;
	int		i = 1;
	while (hotspots[i] && hotspots[i + 1])
	{
		if ((hotspots[i]->pos + hotspots[i]->radius) + (hotspots[i + 1]->pos -
					hotspots[i + 1]->radius) >= (hotspots[i + 1]->pos -
						hotspots[i]->pos))
		{
			count++;
			i++;
		}
		i++;
	}
	return (count);
}
