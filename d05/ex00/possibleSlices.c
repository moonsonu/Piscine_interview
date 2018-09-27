/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   possibleSlices.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksonu <ksonu@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 00:00:49 by ksonu             #+#    #+#             */
/*   Updated: 2018/09/26 01:15:57 by ksonu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdlib.h>
void	recurse(int pizzaSize, struct s_array *arr)
{
	if (pizzaSize == 0) {
		arrayPrint(arr);
		free(arr);
	} else {
		for (int i = 1; i <= pizzaSize; i++) {
			struct s_array *clone = arrayClone(arr);
			arrayAppend(clone, i);
			recurse(pizzaSize - i, clone);
		}
	}
}
void	printPossibleSlices(int pizzaSize)
{
	struct s_array *arr;	
	arr = arrayInit();
	recurse(pizzaSize, arr);
}
