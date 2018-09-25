/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getPlace.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksonu <ksonu@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 23:00:00 by ksonu             #+#    #+#             */
/*   Updated: 2018/09/24 23:48:56 by ksonu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>

int		getPlace(unsigned int parkingRow, int pos)
{
	return (parkingRow & (1 << pos) ? 1 : 0);
}
