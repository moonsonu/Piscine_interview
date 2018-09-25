/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   carPosition.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksonu <ksonu@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 01:34:59 by ksonu             #+#    #+#             */
/*   Updated: 2018/09/25 01:45:31 by ksonu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		carPosition(unsigned int parkingRow)
{
	int		count = 0;
	if (parkingRow == 0 || (parkingRow & (parkingRow - 1)))
		return (-1);
	while (parkingRow != 1)
	{
		parkingRow = parkingRow >> 1;
		count++;
	}
	return (count);
}
