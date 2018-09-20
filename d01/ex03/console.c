/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   console.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksonu <ksonu@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 13:24:14 by ksonu             #+#    #+#             */
/*   Updated: 2018/09/19 21:10:46 by ksonu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BS 4096


struct s_stack	*initStack()
{
	struct s_stack	*stack;

	stack = (struct s_stack*)malloc(sizeof(struct s_stack));
	stack->item = NULL;

	return (stack);
}

void			push(struct s_stack *stack, int idx)
{
	struct s_item	*new;

	new = (struct s_item*)malloc(sizeof(struct s_item));
	new->idx = idx;
	new->next = stack->item;
	stack->item = new;
}

int				pop(struct s_stack *stack)
{
	struct s_item	*r;

	r = (struct s_item*)malloc(sizeof(struct s_item));
	r = stack->item;
	stack->item = stack->item->next;
	return (r->idx);
}

char		*console(void)
{
	struct s_stack	*stack;
	int				r;
	char			*input = (char*)malloc(sizeof(char) * SIZE + 1);
	char			result[BS];
	size_t			l;
	int				i;

	i = 0;
	stack = initStack();
	bzero(result, BS);
	while (1)
	{
		bzero(input, SIZE);
		printf("💌  ");
		r = getline(&input, &l, stdin);
		input[--r] = ' ';
		if (!strcmp(input, "SEND "))
			break;
		else if (!strcmp(input, "UNDO "))
		{
			i = pop(stack);
			bzero(result + i, SIZE - i);
		}
		else
		{
				push(stack, i);
				memmove(result + i, input, strlen(input));
				i += strlen(input);
		}
		printf("%s\n\n", result);
	}
	return (strdup(result));
}
