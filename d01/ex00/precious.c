/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precious.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksonu <ksonu@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 16:20:45 by ksonu             #+#    #+#             */
/*   Updated: 2018/09/18 17:54:35 by ksonu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>
#include <stdlib.h>

void	addnode(struct s_node *node)
{
	struct s_node	*one;
	struct s_node	*before;
	int				i;

	one = node;
	before = NULL;
	one->next = NULL;
	for (i = 0; CS[i]; i++)
	{
		one->c = CS[i];
		if (before != NULL)
		{
			one->prev = before;
		}
		before = one;
		if (CS[i + 1] == '\0')
			break;
		one->next = (struct s_node*)malloc(sizeof(struct s_node));
		one = one->next;
	}
	one->next = node;
	node->prev = one;
}

char	*precious(int *text, int size)
{
	int				i;
	struct s_node	*node;
	char			*result;

	result = (char*)malloc(sizeof(char) * size);
	addnode(node = (struct s_node*)malloc(sizeof(struct s_node)));
	struct s_node *tmp = node;
	for (i = 0; i < 80; i++)
	{
		printf("%c\n", tmp->c);
		tmp = tmp->prev;
	}
	for (i = 0; i < size; i++)
	{
		printf("%d\n", text[i]);
		while (text[i] != 0)
		{
			(text[i] > 0) ? (text[i] += 1) : (text[i] -= 1);
			if (text[i] == 0)
				break;
		}
		result[i] = CS[text[i]];
	}
	return (result);
}
