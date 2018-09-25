/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shift.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksonu <ksonu@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 20:27:39 by ksonu             #+#    #+#             */
/*   Updated: 2018/09/24 22:26:37 by ksonu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>

void	*getnegative(char *bits)
{
	int		i;

	for (i = 0; i < 5; i++)
		(bits[i] == 1) ? '0' : '1';
	for (i = 5; i >= 0; i--)
	{

	}
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

	if (*bits == 1)
		getnegative(bits);
	for (i = 5; i >= 0; i--)
	{
		res += (bits[i] - '0') * k;
		k *= 2;
	}
	return (res);
}
/*#include "header.h"

#include <string.h>

char		*twoscomp(char *a)
{
	int c;

	c = 1;
	for (int i = 5; i >= 0; i--)
	{
		a[i] = (a[i] == '1') ? '0' : '1';
		if (a[i] - '0' + c == 1)
		{
			a[i] = '1';
			c = 0;
		}
		else if (a[i] - '0' + c == 2)
		{
			a[i] = '0';
			c = 1;
		}
	}
	return (a);
}

char		*rightShift(char *bin, int k)
{
	int		len;

	len = strlen(bin);
	for (int i = 0; i < k; i++)
		for (int j = len - 1; j > 0; j--)
			bin[j] = bin[j - 1];
	printf("%s\n", bin);
	return (bin);
}

char		*leftShift(char *bin, int k)
{
	char	*cur;

	for (int i = 0; i < k; i++)
	{
		cur = bin + 1;
		while (*cur && *(cur + 1))
		{
			*cur = *(cur + 1);
			cur++;
		}
		*cur = '0';
	}
	return (bin);
}

int			toInt(char *bits)
{
	int		ret;
	int		sign;
	char	*tmp;

	ret = 0;
	sign = 1;
	tmp = strdup(bits);
	if (*tmp == '1')
	{
		sign = -1;
		tmp = twoscomp(tmp);
	}
	while (*tmp)
	{
		ret = ret * 2 + *tmp - '0';
		tmp += 1;
	}
	return (ret * sign);
}*/
