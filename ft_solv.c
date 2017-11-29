/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgauther <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 17:55:26 by vgauther          #+#    #+#             */
/*   Updated: 2017/11/29 20:35:04 by vgauther         ###   ########.fr       */
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

char	**ft_pull_tetri(char c, t_etris *list)
{
	int i;
	char **tetri;

	i = 0;
	while (list->id != c && list->next)
	{
		list = list->next;
	}
	tetri = list->tetriminos;
	return (tetri);
}

char	**ft_solv(char *str, int size)
{
	char **map;
	char **tetri;
	char **tmp_tetri;
	int num;
	char c;
	int last_char;
	t_etris *list;

	c = 'A';
	last_char = ft_last_char(str);
	map = ft_emptymap(size);
	last_char -= 'A' + 1;
	while (last_char >= num)
	{
		tetri = ft_pull_tetri(c, list);
		tmp_tetri = ft_dupdup(tetri);
		while (ft_is_placed(map,num) == 0)
		{
			if(can_place(tetri, map))
			{
				place_tetri(map, tetri, c);
				c++;
			}
			else
			{
				if(ft_right(tetri, c) == 0)
				{
					tetri = ft_dupdup(tmp_tetri);
					if(ft_bottom(tetri, c) == 0)
						return (NULL);
				}
			}
		}
		num++;
	}
	return (map);
}
