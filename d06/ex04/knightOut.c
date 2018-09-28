/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   knightOut.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksonu <ksonu@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 17:01:16 by ksonu             #+#    #+#             */
/*   Updated: 2018/09/27 21:53:13 by ksonu            ###   ########.fr       */
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

double	probability(int ***check, int x, int y, int n)
{
	double		p = 1.0;

	if ((x < 0 || x > 7) || (y < 0 || y > 7))
		return (1);
	if (n == 0 && (x >= 0 && x <= 7) && (y >= 0 && y <= 7))
		return (0);
	if (check[x][y][n])
		return (check[x][y][n]);
	p = probability(check, x - 2, y + 1, n - 1) * 0.125
		+ probability(check, x - 2, y - 1, n - 1) * 0.125
		+ probability(check, x - 1, y + 2, n - 1) * 0.125
		+ probability(check, x + 1, y + 2, n - 1) * 0.125
		+ probability(check, x + 2, y + 1, n - 1) * 0.125
		+ probability(check, x + 2, y - 1, n - 1) * 0.125
		+ probability(check, x - 1, y - 2, n - 1) * 0.125
		+ probability(check, x + 1, y - 2, n - 1) * 0.125;
	check[x][y][n] = p;
	return (p);
}

int		***initMap()
{
	int		***map = (int***)malloc(sizeof(int**) * 8);
	for (int i = 0; i < 8; i++)
	{
		map[i] = (int**)malloc(sizeof(int*) * 8);
		for (int j = 0; j < 8; j++)
		{
			map[i][j] = (int*)malloc(sizeof(int) * 8);
			for (int k = 0; k < 8; k++)
				map[i][j][k] = 0;
		}
	}
	return (map);
}

double	knightOut(uint64_t board, int n)
{
	int		***map;
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
