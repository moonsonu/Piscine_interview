/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   carPosition.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksonu <ksonu@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 01:46:13 by ksonu             #+#    #+#             */
/*   Updated: 2018/09/25 02:00:55 by ksonu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <math.h>

int		carPosition(unsigned int parkingRow)
{
	int		count = 1;
	if (parkingRow == 0 || (parkingRow & (parkingRow - 1)))
		return (-1);
	else
		count = log2(parkingRow);
	return (count);
}
