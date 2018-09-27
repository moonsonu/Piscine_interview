/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   makeThemEat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksonu <ksonu@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 17:17:48 by ksonu             #+#    #+#             */
/*   Updated: 2018/09/26 19:50:50 by ksonu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>

int		available(struct s_people **people, int nbTable, int totalTime)
{
	int  tmp = 0;
	if (nbTable == 0 || tmp == totalTime)
		return (0);
	for (int i = 0; i < nbTable; i++)
	{
		tmp += people[i]->time;
		available(people, nbTable - 1, tmp);
		tmp = 0;
	}
	return (tmp);
}

int		isPossible(struct s_people **people, int nbTable, int totalTime)
{
	if (!available(people, nbTable, totalTime))
		return (1);
	return (0);
}
