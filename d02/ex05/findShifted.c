/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   findshifted.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksonu <ksonu@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 17:25:08 by ksonu             #+#    #+#             */
/*   Updated: 2018/09/20 19:10:45 by ksonu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>

int		binarySearch(int *rocks, int low, int high, int value)
{
	int		m;

	m = (low + high) / 2;
	if (high < low)
		return (-1);
	if (value == rocks[m])
	{
		while (rocks[m] == rocks[m - 1])
			m--;
		return (m);
	}
	if (value > rocks[m])
		return (binarySearch(rocks, m + 1, high, value));
	return (binarySearch(rocks, low, m - 1, value));
}

int		findPivot(int *rocks, int low, int high)
{
	int		m;

	m = (low + high) / 2;
	if (high < low)
		return (-1);
	if (high == low)
		return (low);
	if ((m < high) && (rocks[m] > rocks[m + 1]))
		return (m);
	if ((m > low) && (rocks[m] < rocks[m - 1]))
		return (m - 1);
	if (rocks[low] >= rocks[m])
		return (findPivot(rocks, low, m - 1));
	return (findPivot(rocks, m + 1, high));
}

int		searchShifted(int *rocks, int length, int value)
{
	int		pivot;

	pivot = findPivot(rocks, 0, length - 1);
	if (pivot == -1)
		return (binarySearch(rocks, 0, length - 1, value));
	if (rocks[pivot] == value)
	{
		while (rocks[pivot] == rocks[pivot - 1])
			pivot--;
		return (pivot);
	}
	if (rocks[0] <= value)
		return (binarySearch(rocks, 0, pivot - 1, value));
	return (binarySearch(rocks, pivot + 1, length - 1, value));
}
