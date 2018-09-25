/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   occupiedPlaces.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksonu <ksonu@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 01:28:00 by ksonu             #+#    #+#             */
/*   Updated: 2018/09/25 01:34:25 by ksonu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		occupiedPlaces(unsigned int parkingRow)
{
	int		count = 0;
	while (parkingRow != 0)
	{
		parkingRow &= (parkingRow - 1);
		count++;
	}
	return (count);
}
