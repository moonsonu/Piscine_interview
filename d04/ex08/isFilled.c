/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isFilled.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksonu <ksonu@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 00:25:26 by ksonu             #+#    #+#             */
/*   Updated: 2018/09/25 01:06:28 by ksonu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>

int		isFilled(unsigned int parkingRow)
{
	return (~((parkingRow + 1) & parkingRow));
}
