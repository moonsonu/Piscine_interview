/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   longestSequence.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksonu <ksonu@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 02:39:00 by ksonu             #+#    #+#             */
/*   Updated: 2018/09/25 12:48:54 by ksonu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		longestSequence(unsigned int parkingRow)
{
	int		count = 0;
	while (parkingRow != 0)
	{
		parkingRow &= (parkingRow << 1);
		count++;
	}
	return (count);
}
