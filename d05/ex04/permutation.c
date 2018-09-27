/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   permutation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksonu <ksonu@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 12:34:24 by ksonu             #+#    #+#             */
/*   Updated: 2018/09/26 13:53:38 by ksonu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>
#include <string.h>

void	swap(char *str, int start, int end)
{
	char	tmp = str[start];
	str[start] = str[end];
	str[end] = tmp;
}

void	permutation(int n, int k, int depth, char *str)
{
	if (depth == k)
		printf("%s\n", str);
	for (int i = depth; i < n; i++)
	{
		swap(str, i, depth);
		permutation(n, k, depth + 1, str);
		swap(str, i, depth);
	}
}

void	printPermutations(char *str)
{
	permutation((int)strlen(str), (int)strlen(str), 0, str);
}
