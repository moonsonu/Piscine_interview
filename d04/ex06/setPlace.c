/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setPlace.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksonu <ksonu@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 00:00:35 by ksonu             #+#    #+#             */
/*   Updated: 2018/09/25 00:06:32 by ksonu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

unsigned int	setPlace(unsigned int parkingRow, int pos)
{
	return (parkingRow | (1 << pos));
}
