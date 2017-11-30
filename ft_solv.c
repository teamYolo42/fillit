/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgauther <vgauther@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 17:55:26 by vgauther          #+#    #+#             */
/*   Updated: 2017/11/30 11:53:16 by vgauther         ###   ########.fr       */
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
			if (ft_isalpha(tetri[y][x]) && map[y][x] == '.')
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

char	**ft_pull_tetri(char c, t_etris *list)
{
	int		i;
	char	**tetri;

	i = 0;
	while (list->id != c && list->next)
	{
		list = list->next;
	}
	tetri = list->tetriminos;
	return (tetri);
}

char	**ft_solv(char *str, int size, char *comb, t_etris *list)
{
	char	**map;
	char	**tetri;
	char	**tmp_tetri;
	int		num;
	int		last_char;

	last_char = ft_last_char(str) - 'A' + 1;
	map = ft_emptymap(size);
	num = 0;
	while (last_char >= num)
	{
		tetri = ft_pull_tetri(comb[num], list);
		tmp_tetri = ft_dupdup(tetri);
		while (ft_is_placed(map, num) == 0)
		{
			if (can_place(tetri, map))
			{
				place_tetri(map, tetri, comb[num]);
				num++;
			}
			else
			{
				if (ft_right(tetri, comb[num]) == 0)
				{
					tetri = ft_dupdup(tmp_tetri);
					if (ft_bottom(tetri, comb[num]) == 0)
						return (NULL);
				}
			}
		}
	}
	return (map);
}

char	**ft_solve(int size, char *str)
{
	char	*comb;
	int		tab[4];
	char	**map;
	char	*plaque;
	t_etris	*list;

	//list = ft_paul();
	tab[0] = (ft_last_char(str) - 'A' + 1);
	tab[1] = 0;
	tab[2] = 1;
	tab[3] = 1;
	plaque = ft_first_comb(ft_last_char(str));
	map = NULL;
	while (map == NULL)
	{
		while (comb != NULL && map == NULL)
		{
			comb = ft_config(0, plaque, tab[3], tab);
			map = ft_solv(str, size, comb, list);
			tab[3]++;
		}
		size++;
	}
	return (map);
}
