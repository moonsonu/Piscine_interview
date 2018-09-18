/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searchPriceV3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksonu <ksonu@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 17:17:15 by ksonu             #+#    #+#             */
/*   Updated: 2018/09/17 22:44:21 by ksonu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

size_t			hash(char *input)
{
	size_t	hashval;
	int					i;

	i = 0;
	hashval = 0;
	while (input[i])
	{
		//hashval = ((hashval << 8) + (int)input[i]);
		hashval += (int)input[i] % 10;
		i++;
	}
	return (hashval);
}

struct s_dict	*dictInit(int capacity)
{
	int		i;
	struct s_dict	*hashtable;

	i = -1;
	hashtable = (struct s_dict*)malloc(sizeof(struct s_item*));
	hashtable->items = (struct s_item**)malloc(sizeof(struct s_item*) * capacity);
	hashtable->capacity = capacity;
	while (++i < capacity)
		hashtable->items[i] = NULL;

	return (hashtable);
}

int				dictInsert(struct s_dict *dict, char *key, struct s_art *value)
{
	int		h;
	struct s_item	*np;

	h = hash(key) % dict->capacity;
	if (dict->items[h] == NULL)
	{
		dict->items[h] = malloc(sizeof(struct s_item));
		np = dict->items[h];
	}
	else
	{
		np = dict->items[h];
		while (np->next != NULL)
		{
			if (strcmp(np->key, key) == 0)
			{
				np->value = value;
				return (1);
			}
			np = np->next;
		}
		np->next = (struct s_item*)malloc(sizeof(struct s_item));
		np = np->next;
	}
	if (np == NULL)
		return (0);
	np->key = strdup(key);
	np->value = value;
	np->next = NULL;
	return (1);
}

struct s_art	*dictSearch(struct s_dict *dict, char *key)
{
	int		h;
	struct s_item	*new;

	h = hash(key) % dict->capacity;
	new = dict->items[h];
	while (new != NULL && new->key != NULL && strcmp(key, new->key) != 0)
		new = new->next;
	if (new == NULL || new->key == NULL || strcmp(key, new->key) != 0)
		return (NULL);
	else
		return (new->value);
}

int				searchPrice(struct s_dict *dict, char *name)
{
	struct s_art	*result;

	result = dictSearch(dict, name);
	return (result->price);
}
