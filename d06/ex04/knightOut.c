/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   knightOut.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksonu <ksonu@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 17:01:16 by ksonu             #+#    #+#             */
/*   Updated: 2018/09/27 21:27:21 by ksonu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		getInitialPos(uint64_t board)
{
	int		pos = 0;
	while (!(board >> pos & 1))
		pos++;
	return (pos);
}

double	probability(int **check, int x, int y, int n)
{
	double		p = 1;

	if ((x < 0 || x > 7) || (y < 0 || y > 7))
	{
		printf("0000000 x %d y %d p %f\n", x, y, p);
		return (1);
	}
	if (n == 0 && (x >= 0 && x <= 7) && (y >= 0 && y <= 7))
	{
		printf("1111111 x %d y %d p %f\n", x, y, p);
		return (0);
	}
	if (check[x][y])
		return (p);
	check[x][y] = 1;
	p = probability(check, x - 2, y + 1, n - 1) * 0.125
		+ probability(check, x - 2, y - 1, n - 1) * 0.125
		+ probability(check, x - 1, y + 2, n - 1) * 0.125
		+ probability(check, x + 1, y + 2, n - 1) * 0.125
		+ probability(check, x + 2, y + 1, n - 1) * 0.125
		+ probability(check, x + 2, y - 1, n - 1) * 0.125
		+ probability(check, x - 1, y - 2, n - 1) * 0.125
		+ probability(check, x + 1, y - 2, n - 1) * 0.125;
	//printf("x %d y %d n %d p %f\n", x, y, n, p);
	return (p);
}

int		**initMap()
{
	int		**map = (int**)malloc(sizeof(int*) * 8);
	for (int i = 0; i < 8; i++)
	{
		map[i] = (int*)malloc(sizeof(int) * 8);
		for (int j = 0; j < 8; j++)
			map[i][j] = 0;
	}
	return (map);
}

double	knightOut(uint64_t board, int n)
{
	int		**map;
	int		i;
	int		j;
	int		pos = getInitialPos(board);
	double	p = 0.0;
	if ((int)board < 0 || n < 0)
		return (-1);
	map = initMap();
	i = pos / 8;
	j = pos % 8;
	p = probability(map, i, j, n);
	return (p);
}
