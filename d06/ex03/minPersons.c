/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minPersons.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksonu <ksonu@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 13:26:14 by ksonu             #+#    #+#             */
/*   Updated: 2018/09/27 17:00:08 by ksonu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>

int		minPersons(int elements, int minPercentage)
{
	int			i = 0;
	double		per = 1;
	int			people = 0;
	
	while (i < elements)
	{
		per *= (double)(elements - i) / (double)elements;
		if (((double)1 - per) <= ((double)minPercentage / (double)100))
			people += 1;
		else
			return (people + 1);
		i++;
	}
	return (0);
}
