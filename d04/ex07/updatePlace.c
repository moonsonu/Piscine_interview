/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   updatePlace.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksonu <ksonu@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 00:07:04 by ksonu             #+#    #+#             */
/*   Updated: 2018/09/25 00:24:42 by ksonu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

unsigned int	updatePlace(unsigned int parkingRow, int pos, int value)
{
	if (value == 1)
		return (parkingRow | (1 << pos));
	else
		return (parkingRow & (1 << pos));
}
