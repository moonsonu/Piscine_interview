/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   permutationV2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksonu <ksonu@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 13:54:00 by ksonu             #+#    #+#             */
/*   Updated: 2018/09/26 17:15:32 by ksonu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void	swap(char *str, int start, int end)
{
	char	tmp = str[start];
	str[start] = str[end];
	str[end] = tmp;
}

void	permutation(char *str, int len, int depth, struct s_dict *dict)
{
	if (depth == len && dictSearch(dict, str) < 0) {
		dictInsert(dict, str, 1);
		printf("%s\n", str);
	} else {
		for (int i = depth; i < len; i++) {
			swap(str, i, depth);
			permutation(str, len, depth + 1, dict);
			swap(str, i, depth);
		}
	}
}

void	printUniquePermutations(char *str)
{
	struct s_dict	*dict = dictInit((int)strlen(str));
	permutation(str, (int)strlen(str), 0, dict);
}
