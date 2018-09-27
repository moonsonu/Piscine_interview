/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sinkIsland.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksonu <ksonu@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 01:33:48 by ksonu             #+#    #+#             */
/*   Updated: 2018/09/26 12:33:32 by ksonu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>

void	sinkIsland(int **map, int row, int col)
{
	if (map[row] == 0 || map[row][col] == -1 || map[row][col] == 0 ||
			col < 0 || row < 0)
		return ;
	map[row][col] = 0;
	sinkIsland(map, row, col - 1);
	sinkIsland(map, row, col + 1);
	sinkIsland(map, row - 1 , col);
	sinkIsland(map, row + 1, col);
}
