/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   findParent.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksonu <ksonu@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 13:08:32 by ksonu             #+#    #+#             */
/*   Updated: 2018/09/22 14:31:21 by ksonu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <string.h>
#include <stdio.h>

int				finddepth(struct s_node *root, char *species)
{
	int		tmp = 0;

	if (!root)
		return (0);
	if (!strcmp(root->name, species))
		return (tmp);
	while (*root->children)
	{
		tmp = 1 + finddepth(*root->children, species);
		root->children++;
	}
	return (tmp);
}

struct s_node	*findParent(struct s_node *root, char *firstSpecies,
		char *secondSpecies)
{
	struct s_node	*node;

	node = NULL;
	//char	*p1;
	//char	*p2;
	(void)secondSpecies;
	if (root == NULL)
		return (0);
	printf("%d\n", finddepth(root, firstSpecies));
	printf("%d", finddepth(root, secondSpecies));
	//finddepth(root, secondSpecies);
	return(node);
}
