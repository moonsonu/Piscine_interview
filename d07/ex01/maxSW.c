/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maxSW.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksonu <ksonu@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/28 14:19:20 by ksonu             #+#    #+#             */
/*   Updated: 2018/09/28 18:28:09 by ksonu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdlib.h>
#include <limits.h>
#include <stdio.h>

struct s_deque	*dequeInit(void)
{
	struct s_deque	*new = (struct s_deque*)malloc(sizeof(struct s_deque));

	new->first = NULL;
	new->last = NULL;
	return (new);
}

void			pushFront(struct s_deque *deque, int value)
{
	struct s_dequeNode *tmp;

	tmp = (struct s_dequeNode*)malloc(sizeof(struct s_dequeNode));
	tmp->value = value;
	tmp->next = deque->first;
	if (deque->first == NULL)
		deque->last = tmp;
	else
		deque->first->prev = tmp;
	tmp->prev = NULL;
	deque->first = tmp;
}

void			pushBack(struct s_deque *deque, int value)
{
	struct s_dequeNode	*tmp;

	tmp = (struct s_dequeNode*)malloc(sizeof(struct s_deque));
	tmp->value = value;
	tmp->prev = deque->last;
	if (deque->first == NULL)
		deque->first = deque->last = tmp;
	else
		deque->last->next = tmp;
	tmp->next = NULL;
	deque->last = tmp;
}

int				popFront(struct s_deque *deque)
{
	struct s_dequeNode	*tmp;

	if (deque->first != NULL)
	{
		tmp = deque->first;
		deque->first = deque->first->next;
		if (!deque->first)
			deque->last = NULL;
		else
			deque->first = tmp->next;
		return (tmp->value);
	}
	return (INT_MIN);
}

int				popBack(struct s_deque *deque)
{
	struct s_dequeNode	*tmp;

	if (deque->last != NULL)
	{
		tmp = deque->last;
		deque->last = deque->last->prev;
		if (!deque->last)
			deque->first = NULL;
		else
			deque->last = tmp->prev;
		return (tmp->value);
	}
	return (INT_MIN);
}

int				isEmpty(struct s_deque *deque)
{
	return ((deque->first != NULL) && (deque != NULL) ? 0 : 1);
}

struct s_max	*maxSlidingWindow(int *arr, int n, int k)
{
	struct s_max	*res = malloc(sizeof(struct s_max));
	struct s_deque	*deque = dequeInit();
//	int				max = 0;
//	int				t = k;
	int				j = 0;
	res->length = n - k + 1;
	res->max = malloc(sizeof(int) * (n - k) + 1);

	for (int i = 0; i < n; i++)
	{
		while (!isEmpty(deque) && deque->last->value < arr[i])
		{
			popBack(deque);
		}
		pushBack(deque, arr[i]);
		if (i >= k - 1)
		{
			res->max[j++] = deque->first->value;
			if (arr[i - k + 1] == deque->first->value)
				popFront(deque);
		}
	}
	return (res);
}
/*	for (int i = 0; i < n; i++)
	{
		if (!isEmpty(deque) && deque->last->value < arr[i])
			pushBack(deque, arr[i]);
		pushFront(deque, arr[i]);
		t -= 1;
		if (t == 0 || i >= k)
		{
			res->max[j++] = deque->last->value;
			popFront(deque);
		}
	}
	return (res);
}

	for (int i = 0; i < k; i++)
	{
		pushBack(deque, arr[i]);
		if (max < arr[i])
			max = arr[i];
	}
	for (int i = 0; i < (n - k) + 1; i++)
	{
		res->max[i] = max;
		max = arr[i + k];
		popFront(deque);
		pushFront(deque, arr[i + k]);
		if (max < arr[i + k])
			max = arr[i + k];
	}
	return (res);
}*/
