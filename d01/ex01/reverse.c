/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksonu <ksonu@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 19:32:21 by ksonu             #+#    #+#             */
/*   Updated: 2018/09/18 20:39:18 by ksonu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>

void	reverse(struct s_node *lst, int i)
{
	if (lst != NULL)
	{
		reverse(lst->next, 0);
		printf("%s%s", lst->word, i ? "" : " ");
	}
}

void	printReverse(struct s_node *lst)
{
	reverse(lst, 1);
}
