/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgauther <vgauther@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 17:55:26 by vgauther          #+#    #+#             */
/*   Updated: 2017/11/30 19:06:07 by pcartau          ###   ########.fr       */
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

char	**ft_pull_tetri(char c, t_tetri *list)
{
	int		i;
	char	**tetri;

	i = 0;
	while (list->id != c && list)
	{
	//	ft_puttab(list->map);
		list = list->next;
	}
	tetri = list->map;
	return (tetri);
}

char	**ft_solv(char *str, int size, char *comb, t_tetri *list)
{
	t_variable	v;
	int			num;
	int			last_char;

	int x;
	x= 0;

	last_char = ft_last_char(str) - 'A' + 1;
	v.map = ft_emptymap(size);
	num = 0;
	while (last_char >= num)
	{
		v.tetri = ft_pull_tetri(comb[num], list);
		while (ft_is_placed(v.map, num) == 0)
		{
			if (can_place(v.tetri, v.map))
				place_tetri(v.map, v.tetri, comb[num++]);
			else
			{
				if (ft_right(v.tetri, comb[num]) == 0)
				{
					v.tetri = ft_dupdup(v.tmp_tetri);
					if (ft_bottom(v.tetri, comb[num]) == 0)
						return (NULL);
				}
			}
		}
	}
	return (v.map);
}

char	**ft_solve(int size, char *str)
{
	char	*comb;
	int		tab[4];
	char	**map;
	char	*plaque;
	t_tetri	*list;

	tab[0] = (ft_last_char(str) - 'A' + 1 );
	tab[1] = 0;
	tab[2] = 1;
	tab[3] = 1;
	list = ft_getpiece(str, ft_last_char(str));
	plaque = ft_first_comb(ft_last_char(str));
	printf("%s\n", plaque);
	map = NULL;
	while (map == NULL)
	{
		ft_change_size(list, size);
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
