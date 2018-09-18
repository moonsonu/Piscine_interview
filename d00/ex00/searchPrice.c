/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searchPrice.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksonu <ksonu@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 10:06:53 by ksonu             #+#    #+#             */
/*   Updated: 2018/09/17 11:34:32 by ksonu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "header.h"

int		searchPrice(struct s_art **arts, char *name)
{
	int		i;

	i = 0;
	while (arts[i])
	{
		if (!strcmp(arts[i]->name, name))
			return (arts[i]->price);
		else
			i++;
	}
	return (-1);
}
