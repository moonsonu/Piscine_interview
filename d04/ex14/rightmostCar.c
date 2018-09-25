/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reightmostCar.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksonu <ksonu@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 02:30:25 by ksonu             #+#    #+#             */
/*   Updated: 2018/09/25 02:38:17 by ksonu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>

int		rightmostCar(unsigned int parkingRow)
{
	int		count = 0;
	
	parkingRow ^= parkingRow - 1;
	printf("%u\n", parkingRow);
	while (parkingRow != 1)
	{
		parkingRow = parkingRow >> 1;
		count++;
	}
	return (count);
}
