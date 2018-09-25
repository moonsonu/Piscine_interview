/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shift.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksonu <ksonu@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 20:27:39 by ksonu             #+#    #+#             */
/*   Updated: 2018/09/24 22:37:50 by ksonu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>
#include <string.h>

void	*getnegative(char *bits)
{
	int c;

	c = 1;
	for (int i = 5; i >= 0; i--)
	{
		bits[i] = (bits[i] == '1') ? '0' : '1';
		if (bits[i] - '0' + c == 1)
		{
			bits[i] = '1';
			c = 0;
		}
		else if (bits[i] - '0' + c == 2)
		{
			bits[i] = '0';
			c = 1;
		}
	}
	return (bits);
}

char	*rightShift(char *bin, int k)
{
	int		i;
	int		j;

	for (i = 0; i < k; i++)
	{
		for (j = 5; j > 0; j--)
			bin[j] = bin[j - 1];
	}
	return (bin);
}

char	*leftShift(char *bin, int k)
{
	int		i;
	char	*res = bin;
	int		j = k;

	i = 5;
	while (j-- > 0)
	{
		res[i - k] = bin[i];
		i--;
	}
	for (i = 5; i > k + 1; i--)
		res[i] = '0';
	return (res);
}

int		toInt(char *bits)
{
	int		i;
	int		k = 1;
	int		res = 0;
	int		sign = 1;
	char	*tmp = strdup(bits);

	if (*bits == '1')
	{
		sign = -1;
		tmp = getnegative(tmp);
	}
	for (i = 5; i >= 0; i--)
	{
		res += (tmp[i] - '0') * k;
		k *= 2;
	}
	return (res * sign);
}
