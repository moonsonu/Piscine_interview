/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverseV2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksonu <ksonu@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 20:53:57 by ksonu             #+#    #+#             */
/*   Updated: 2018/09/19 21:11:38 by ksonu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>
#include <stdlib.h>

struct s_stack	*stackInit(void)
{
	struct s_stack	*stack;

	stack = (struct s_stack*)malloc(sizeof(struct s_stack));
	stack->item = NULL;

	return (stack);
}

void			*pop(struct s_stack *stack)
{
	struct s_item	*r;

	r = (struct s_item*)malloc(sizeof(struct s_item));
	r = stack->item;
	stack->item = stack->item->next;
	return (r->word);
}

void			push(struct s_stack *stack, char *word)
{
	struct s_item	*new;

	new = (struct s_item*)malloc(sizeof(struct s_item));
	new->word = word;
	new->next = stack->item;
	stack->item = new;
}

void			printReverseV2(struct s_node *lst)
{
	struct s_stack	*stack;
	struct s_node	*node;
	char			*r;

	stack = stackInit();
	node = lst;
	while (node != NULL)
	{
		push(stack, node->word);
		node = node->next;
	}
	while (stack->item != NULL)
	{
		r = pop(stack);
		if (r != NULL)
		{
			if (stack->item == NULL)
				printf("%s", r);
			else
				printf("%s ", r);
		}
	}
	printf("\n");
}
