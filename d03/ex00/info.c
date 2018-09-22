/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksonu <ksonu@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 21:33:18 by ksonu             #+#    #+#             */
/*   Updated: 2018/09/21 13:36:58 by ksonu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdlib.h>
#include <string.h>

int				getMin(struct s_node *root)
{
	int		r;
	int		lr;
	int		rr;

	if (!root)
		return (0);
	r = root->value;
	lr = getMin(root->left);
	rr = getMin(root->right);
	if (lr < r)
		r = lr;
	if (rr < r)
		r = rr;
	return (r);
}

int				getMax(struct s_node *root)
{
	int		r;
	int		lr;
	int		rr;

	if (!root)
		return (0);
	r = root->value;
	lr = getMax(root->left);
	rr = getMax(root->right);
	if (lr > r)
		r = lr;
	if (rr > r)
		r = rr;
	return (r);
}

int				getElements(struct s_node *root)
{
	if (!root)
		return (0);
	else
		return ((getElements(root->left) + getElements(root->right) + 1));
}

int				getHeight(struct s_node *root)
{
	int		lh;
	int		rh;
	
	if (!root)
		return (0);
	else
	{
		lh = getHeight(root->left);
		rh = getHeight(root->right);
		return (1 + ((lh > rh) ? lh : rh));
	}
}

int				getisBst(struct s_node *root)
{
	struct s_node	*tmp;

	tmp = NULL;
	if (root)
	{
		if (!getisBst(root->left))
			return (0);
		if (tmp != NULL && root->value <= tmp->value)
			return (0);
		tmp = root;
		return (getisBst(root->right));
	}
	return (1);
}

int				getisBalanced(struct s_node *root)
{
	int		lh;
	int		rh;

	lh = 0;
	rh = 0;
	if (!root)
		return (0);
	lh = getHeight(root->left);
	rh = getHeight(root->right);
	if ((lh - rh >= 2) || (rh- lh >= 2))
		return (0);
	return (1);
}
struct s_info	getInfo(struct s_node *root)
{
	struct s_info	info;

	info.min = getMin(root);
	info.max = getMax(root);
	info.elements = getElements(root);
	info.height = getHeight(root);
	info.isBST = getisBst(root);
	info.isBalanced = getisBalanced(root);

	return (info);
}
