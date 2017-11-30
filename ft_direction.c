/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_direction.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgauther <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 19:00:04 by vgauther          #+#    #+#             */
/*   Updated: 2017/11/30 14:06:39 by vgauther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		strheight(char **tab)
{
	int y;

	y = 0;
	while (tab[y])
		y++;
	return (y);
}

void	ft_swap(char **tetri, int x, int y, int fnct)
{
	char	tmp;
	int		target_x;
	int		target_y;

	tmp = tetri[y][x];
	if (fnct == 42)
	{
		target_x = x + 1;
		target_y = y;
	}
	else
	{
		target_x = x;
		target_y = y + 1;
	}
	tetri[y][x] = tetri[target_y][target_x];
	tetri[target_y][target_x] = tmp;
}

int		ft_right(char **tetri, char c)
{
	int x;
	int end;
	int height;
	int y;

	y = -1;
	end = ft_strlen(tetri[0]);
	height = strheight(tetri);
	while (height >= 0)
		if (tetri[height--][end] != '.')
			return (0);
	while (tetri[++y])
	{
		x = -1;
		while (tetri[y][++x])
			if (tetri[y][x] == c)
				ft_swap(tetri, x, y, 42);
	}
	return (1);
}

int		ft_bottom(char **tetri, char c)
{
	int x;
	int end;
	int height;
	int y;

	y = -1;
	end = ft_strlen(tetri[0]);
	height = strheight(tetri);
	while (end >= 0)
		if (tetri[height][end--] != '.')
			return (0);
	while (tetri[++y])
	{
		x = -1;
		while (tetri[y][++x])
			if (tetri[y][x] == c)
				ft_swap(tetri, x, y, 101);
	}
	return (1);
}
