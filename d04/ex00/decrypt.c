/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decrypt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksonu <ksonu@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 11:31:37 by ksonu             #+#    #+#             */
/*   Updated: 2018/09/24 20:47:35 by ksonu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>
#include <stdlib.h>

char	*getSum(char *a, char *b)
{
	int		i;
	int		remain = 0;
	char	*r;

	r = (char*)malloc(sizeof(char) * 5);
	for (i = 5; i >= 0; i--)
	{
		if (a[i] == '1' && b[i] == '1')
		{
			r[i] = (remain + 0) % 2 + '0';
			remain = 1;
		}
		if ((a[i] == '1' && b[i] == '0') || (a[i] == '0' && b[i] == '1'))
		{
			r[i] = (remain + 1) % 2 + '0';
			remain /= 2;
		}
		if (a[i] == '0' && b[i] == '0')
		{
			r[i] = (remain + 0) % 2 + '0';
			remain /=2;
		}
	}
	return (r);
}

int			toInt(char *bits)
{
	int		res;
	int		k = 1;
	int		i;

	res = 0;
	for (i = 5; i >= 0; i--)
	{
		res += (bits[i] - '0') * k;
		k *= 2;
	}
	return (res);
}
