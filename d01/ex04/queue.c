/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksonu <ksonu@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 16:47:55 by ksonu             #+#    #+#             */
/*   Updated: 2018/09/19 22:16:43 by ksonu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdlib.h>
#include <stdio.h>

struct s_queue	*queueInit(void)
{
	struct s_queue	*queue;
	
	queue = (struct s_queue*)malloc(sizeof(struct s_queue));
	queue->first = NULL;
	queue->last = NULL;
	return (queue);
}

char			*dequeue(struct s_queue *queue)
{
	struct s_node	*tmp;

	if (queue->first != NULL)
	{
		tmp = queue->first;
		queue->first = tmp->next;
		if (!queue->first)
			queue->last = NULL;
		return (tmp->message);
	}
	else
		return (NULL);
}

void			enqueue(struct s_queue *queue, char *message)
{
	struct s_node	*new;

	new = (struct s_node*)malloc(sizeof(struct s_node));
	new->next = NULL;
	new->message = message;
	if (queue->first == NULL)
	{
		queue->last = new;
		queue->first = new;
	}
	else
	{
		queue->last->next = new;
		queue->last = new;
	}
}

char			*peek(struct s_queue *queue)
{
	if (queue->first != NULL)
		return (queue->first->message);
	else
		return (NULL);
}

int				isEmpty(struct s_queue *queue)
{
	return ((queue->first != NULL) && (queue != NULL) ? 0 : 1);
}
