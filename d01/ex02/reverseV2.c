/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverseV2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksonu <ksonu@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 20:53:57 by ksonu             #+#    #+#             */
/*   Updated: 2018/09/18 21:09:44 by ksonu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

struct s_stack	*stackInit(void)
{
	struct s_stack	*stack;

	stack = (struct s_stack*)malloc(sizeof(struct s_stack));
	stack->item = (struct s_item)malloc(sizeof(struct s_item));

	return (stack);
}

void			*pop(struct s_stack *stack)
{

}

void			push(struct s_stack *stack, char *word)
{
}

void			printReverseV2(struct s_node *lst)
{
	struct s_stack	*stack;

	stack = stackInit();

}
