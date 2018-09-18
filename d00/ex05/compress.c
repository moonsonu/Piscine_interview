/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksonu <ksonu@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 14:35:03 by ksonu             #+#    #+#             */
/*   Updated: 2018/09/18 15:56:07 by ksonu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

//return hash result
size_t	hash(char *input)
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

//initialize the dictionnary, given as parameter the capacity of the array.
struct s_dict *dictInit(int capacity)
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

//add one item in the dictionnary, if FAIL return 0, otherwise 1
int				dictInsert(struct s_dict *dict, char *key, int value)
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

//find one element in the dictionnary, if not found, return -1
int				dictSearch(struct s_dict *dict, char *key)
{
	int		h;
	struct s_item	*new;

	h = hash(key) % dict->capacity;
	new =  dict->items[h];
	while (new != NULL && new->key != NULL && strcmp(key, new->key) != 0)
		new = new->next;
	if (new == NULL || new->key == NULL || strcmp(key, new->key) != 0)
		return (-1);
	else
		return (0);
}

int		ft_counter(char const *str, char c)
{
	int		i;
	int		word;

	i = 0;
	word = 0;
	while (str[i] != '\0')
	{
		while (str[i] != c)
		{
			if (str[i] != '\0')
				i++;
			else
				break ;
		}
		while (str[i] == c)
			i++;
		word++;
	}
	return (word);
}

char		*ft_string(char const *s, char c)
{
	char	*w;
	int		i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	w = (char*)malloc(sizeof(char) * (i + 1));
	i = 0;
	while (s[i] && s[i] != c)
	{
		w[i] = s[i];
		i++;
	}
	w[i] = '\0';
	return (w);
}

char				**ft_strsplit(char const *s, char c)
{
	char	**rc;
	int		index;
	int		a;

	if (!s)
		return (NULL);
	a = ft_counter(s, c);
	rc = (char **)malloc(sizeof(char *) * (a + 1));
	if (!rc)
		return (NULL);
	index = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s && *s != c)
		{
			rc[index] = ft_string(s, c);
			index++;
			while (*s && *s != c)
				s++;
		}
	}
	rc[index] = 0;
	return (rc);
}

char	*compress(char *book, struct s_dict *dict)
{
	int		i;
	char	**word;
	char	*compress;

	word = ft_strsplit(book, ' ');
	for (i = 0; word[i]; i++)
	{
		if (dictSearch(dict, word[i]))
	}
	return ();
}
