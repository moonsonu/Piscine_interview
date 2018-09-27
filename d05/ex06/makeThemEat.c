/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   makeThemEat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksonu <ksonu@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 17:17:48 by ksonu             #+#    #+#             */
/*   Updated: 2018/09/26 21:05:05 by ksonu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>

int		available(struct s_people **people, int nbTable, int totalTime)
{
	int		tmp = totalTime;
	if (nbTable == 0 && totalTime >= 0)
		return (1);
	for (int i = 0; i < nbTable; i++)
	{
		printf("before %d\n", tmp);
		tmp -= people[i]->time;
		available(people, nbTable - 1, totalTime - tmp);
	}
	printf("after total%d\n", totalTime);
	printf("after tmp%d\n", tmp);
	return (totalTime - tmp);
}

int		isPossible(struct s_people **people, int nbTable, int totalTime)
{
	if (available(people, nbTable, totalTime * nbTable) >= 0)
	{
		printf("result %d\n", available(people, nbTable, totalTime * nbTable));
		return (1);
	}
		printf("result %d\n", available(people, nbTable, totalTime * nbTable));
	return (0);
}
