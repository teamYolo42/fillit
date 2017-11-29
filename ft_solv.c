/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgauther <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 17:55:26 by vgauther          #+#    #+#             */
/*   Updated: 2017/11/29 18:43:49 by vgauther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	place_tetri(char **map, char **tetri, char c)
{
	int x;
	int y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			map[y][x] = (tetri[y][x] == c ? c : map[y][x]);
			x++;
		}
		y++;
	}
}

int		can_place(char **tetri, char **map)
{
	int x;
	int y;

	y = 0;
	while (tetri[y])
	{
		x = 0;
		while (tetri[y][x])
		{
			if(ft_isalpha(tetri[y][x]) && map[y][x] == '.')
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

char	**ft_pull_tetri(char c, )
{

	return (tetri)
}

char	**ft_solv(char *str, int size)
{
	char **map;
	char last_char;

	last_char = ft_last_char(str);
	map = ft_emptymap(size);
	while (last_char >= 'A')
	{
		tetri = 
		if(can_place(tetri,map))
		{
			
		}
		last_char--;
	}
	return (map);
}
