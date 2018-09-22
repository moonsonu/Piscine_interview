/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   createBST.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksonu <ksonu@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 12:38:55 by ksonu             #+#    #+#             */
/*   Updated: 2018/09/21 13:00:10 by ksonu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdlib.h>

struct s_node	*initBST(int value)
{
	struct s_node	*b;

	b = (struct s_node*)malloc(sizeof(struct s_node));
	b->value = value;
	b->right = NULL;
	b->left = NULL;
	return (b);
}

struct s_node	*insertNode(int *arr, int s, int e)
{
	struct s_node	*b;
	int				mid;

	if (s > e)
		return (NULL);
	mid= (s + e) / 2;
	b = initBST(arr[mid]);
	b->left = insertNode(arr, s, mid - 1);
	b->right = insertNode(arr, mid + 1, e);

	return (b);
}

struct s_node	*createBST(int *arr, int n)
{
	struct s_node	*bst;

	bst = insertNode(arr, 0, n - 1);
	return (bst);
}
