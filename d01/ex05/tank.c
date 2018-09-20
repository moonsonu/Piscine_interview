/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tank.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksonu <ksonu@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 18:58:59 by ksonu             #+#    #+#             */
/*   Updated: 2018/09/19 23:34:31 by ksonu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdlib.h>
#include <stdio.h>

struct s_elem	*initElem(void)
{
	struct s_elem	*elem;
	
	elem = (struct s_elem*)malloc(sizeof(struct s_elem));
	elem->energy = 0;
	elem->next = NULL;
	return (elem);
}

struct s_stack	*initStack(void)
{
	struct s_stack	*stack;

	stack = (struct s_stack*)malloc(sizeof(struct s_stack));
	stack->sum = 0;
	return (stack);
}
struct s_tank	*initTank(void)
{
	struct s_tank	*tank;

	tank = (struct s_tank*)malloc(sizeof(struct s_tank));
	tank->stacks = (struct s_stack**)malloc(sizeof(struct s_stack));
	tank->n = 0;
	tank->stacks[tank->n] = (struct s_stack*)malloc(sizeof(struct s_stack));
	tank->stacks[tank->n]->elem = (struct s_elem*)malloc(sizeof(struct s_elem));
	tank->stacks[tank->n]->elem->energy = 0;
	tank->stacks[tank->n]->elem->next = NULL;
	return (tank);
}

void			tankPush(struct s_tank *tank, int energy)
{
	struct s_stack	*curr;
	struct s_elem	*nelem;

	curr = tank->stacks[tank->n];
	nelem = initElem();
	if (curr && curr->sum + energy > 1000)
	{
		tank->n += 1;
		curr = tank->stacks[tank->n];
		curr = initStack();
		curr->elem = initElem();
	}
	curr->sum += energy;
	if (curr->elem == NULL)
	{
		nelem = curr->elem;
		nelem->energy = energy;
	}
	else if (curr->elem)
	{
		nelem->energy = energy;
		curr->elem->next = nelem;
		nelem = curr->elem;
	tank->stacks[tank->n] = curr;
	}

	tankPop(tank);
}

int				tankPop(struct s_tank *tank)
{
	struct s_stack	*curr;
	struct s_elem	*tmp;
	int				energy;

	curr = tank->stacks[tank->n];
	tmp = initElem();
	energy = 0;
	if (curr != NULL)
	{
			tmp = curr->elem;
			if (!curr->elem)
				curr->elem->next = NULL;
			curr->elem = tmp->next;
			energy = tmp->energy;
			printf("energypop: %d\n", energy);
	}
	return (0);
}
