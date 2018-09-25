/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clearPlace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksonu <ksonu@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 23:38:35 by ksonu             #+#    #+#             */
/*   Updated: 2018/09/24 23:59:53 by ksonu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

unsigned int	clearPlace(unsigned int parkingRow, int pos)
{
	return (parkingRow ^ (1 << pos));
}
