/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bits.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksonu <ksonu@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 12:58:32 by ksonu             #+#    #+#             */
/*   Updated: 2018/09/24 20:44:30 by ksonu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdlib.h>
#include <stdio.h>

char	*negation(char *a)
{
	int		i;
	int		j = 0;
	char	*res;
	
	res = (char*)malloc(sizeof(char) * 3);
	for (i = 3; i >= 0; i--)
	{
		res[j] = a[i];
		j++;
	}
	return (res);
}

char	*getAnd(char *a, char *b)
{
	char	*res;
	int		i;
	
	if (a[0] == '~')
		a = negation(a);
	if (b[0] == '~')
		b = negation(b);
	res = (char*)malloc(sizeof(char));
	for (i = 0; i < 4; i++)
	{
		if (a[i] == '1' && b[i] == '1')
			res[i] = '1';
		else
			res[i] = '0';
	}
	return (res);
}

char	*getOr(char *a, char *b)
{
	char	*res;
	int		i;
	
	if (a[0] == '~')
		a = negation(a);
	if (b[0] == '~')
		b = negation(b);
	res = (char*)malloc(sizeof(char));
	for (i = 0; i < 4; i++)
	{
		if (a[i] == '0' && b[i] == '0')
			res[i] = '0';
		else
			res[i] = '1';
	}
	return (res);
}

int			toInt(char *bits)
{
	int		res = 0;
	int		k = 1;

	for (int i = 3; i >= 0; i--)
	{
		res += (bits[i] - '0') * k;
		k *= 2;
	}
	return (res);
}
