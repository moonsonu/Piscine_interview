/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   leftmostCar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksonu <ksonu@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 02:23:48 by ksonu             #+#    #+#             */
/*   Updated: 2018/09/25 02:43:32 by ksonu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		leftmostCar(unsigned int parkingRow)
{
	int		count = 0;

	while (parkingRow != 1)
	{
		parkingRow = parkingRow >> 1;
		count++;
	}
	return (count);
}
