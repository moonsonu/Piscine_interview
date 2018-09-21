/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortStone.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksonu <ksonu@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 23:45:42 by ksonu             #+#    #+#             */
/*   Updated: 2018/09/20 13:18:08 by ksonu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdlib.h>
#include <stdio.h>

void	swap(struct s_group *p1, struct s_group *p2)
{
	int		ns;
	struct s_stone	*first;
	struct s_stone	*last;

	first = p1->first;
	last = p1->last;
	ns = p1->size;
	p1->first = p2->first;
	p1->last = p2->last;
	p1->size = p2->size;
	p2->first = first;
	p2->last = last;
	p2->size = ns;
}

struct s_group		*newgroup(struct s_stone *stone)
{
	struct s_group	*r;

	r = (struct s_group*)malloc(sizeof(struct s_group));
	r->first = stone;
	r->last = stone;
	r->size = stone->size;
	return (r);
}

void	makegroup(struct s_group **g, struct s_stone *s)
{
	struct s_group *tmp;

	if (*g == NULL)
		*g = newgroup(s);
	else
	{
		tmp = *g;
		while (tmp->next)
		{
			if (tmp->size == s->size)
			{
				tmp->last->next = s;
				tmp->last = s;
				return;
			}
			tmp = tmp->next;
		}
		tmp->next = newgroup(s);
	}
}

struct s_stone	*merge(struct s_group *g)
{
	struct s_stone	*result = NULL;
	struct s_stone	*tmp;

	while (g)
	{
		if (!result)
			result = g->first;
		else
			tmp->next = g->first;
		tmp = g->last;
		g = g->next;
	}
	tmp->next = NULL;
	return (result);
}

struct s_group	*getgroup(struct s_stone *stone)
{
	struct s_group		*r = NULL;

	while (stone)
	{
		makegroup(&r, stone);
		stone = stone->next;
	}
	return (r);
}

void	sortStones(struct s_stone **stone)
{
	struct s_group		*g;
	int					flag;
	struct s_group		*p1 = NULL;
	struct s_group		*p2 = NULL;

	g = getgroup(*stone);
	flag = 1;
	while (flag)
	{
		flag = 0;
		p1 = g;
		while (p1->next != p2)
		{
			if (p1->size > p1->next->size)
			{
				swap(p1, p1->next);
				flag = 1;
			}
			p1 = p1->next;
		}
		p2 = p1;
	}
	*stone = merge(g);
}
