/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xor.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksonu <ksonu@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 22:38:30 by ksonu             #+#    #+#             */
/*   Updated: 2018/09/24 22:59:05 by ksonu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdlib.h>

char	*getXor(char *a, char *b)
{
	char	*res;

	res = (char*)malloc(sizeof(char));
	for (int i = 0; i < 6; i++)
	{
		if (a[i] == b[i])
			res[i] = '0';
		else
			res[i] = '1';
	}
	return (res);
}

int		toInt(char *bits)
{
	int		i;
	int		k = 1;
	int		res = 0;

	for (i = 5; i >= 0; i--)
	{
		res += (bits[i] - '0') * k;
		k *= 2;
	}
	return (res);
}
