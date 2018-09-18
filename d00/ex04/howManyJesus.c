/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   howManyJesus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksonu <ksonu@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 09:26:35 by ksonu             #+#    #+#             */
/*   Updated: 2018/09/18 14:24:13 by ksonu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <string.h>

#define D 256
#define Q 101

static int	gethvalue(int len, char *str)
{
	int		i;
	int		hvalue = 0;

	i = 0;
	while (i < len)
	{
		hvalue = ((D * hvalue) + str[i]) % Q;
		i++;
	}
	return (hvalue);
}

int		howManyJesus(char *bible, char *jesus)
{
	int		b = strlen(bible);
	int		j = strlen(jesus);
	int		bhvalue;
	int		jhvalue;
	int		i;
	int		k;
	int		count;
	int		h;

	if (b < j)
		return (0);
	if (!bible || !jesus)
		return (0);
	i = 0;
	h = 1;
	count = 0;
	for (i = 0; i < j - 1; i++)
		h = (h * D) % Q;
	bhvalue = gethvalue(j, bible);
	jhvalue = gethvalue(j, jesus);
	i = 0;
	while (i < (b - j) - 1)
	{
		if (bhvalue == jhvalue)
		{
			for (k = 0; k < j; k++)
				if (bible[i + k] != jesus[k])
					break;
			count += (k < j) ? 0 : 1;
			//if (k == j)
			//	count += 1;
		}
		if (i < (b - j))
		{
			bhvalue = (D * (bhvalue - bible[i] * h) + bible[i + j]) % Q;
			if (bhvalue < 0)
				bhvalue = bhvalue + Q;
		}
		i++;
	}
	return (count);
}
