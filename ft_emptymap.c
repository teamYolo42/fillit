/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_emptymap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcartau <pcartau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 19:18:02 by pcartau           #+#    #+#             */
/*   Updated: 2017/11/30 11:22:25 by vgauther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**ft_emptymap(int size)
{
	char	**tab;
	int		x;
	int		y;

	y = 0;
	if (!(tab = (char **)malloc(sizeof(char *) * (size + 1))))
		return (NULL);
	while (y < size)
	{
		x = 0;
		if (!(tab[y] = (char *)malloc(sizeof(char) * size + 1)))
			return (NULL);
		while (x < size)
		{
			tab[y][x] = '.';
			x++;
		}
		tab[y][x] = '\0';
		y++;
	}
	tab[y] = 0;
	return (tab);
}

void	ft_change_size(t_etris *list, size_t size)
{
	char	**tetris;
	int		x;
	int		y;

	y = 0;
	while (list)
	{
		tetris = ft_dupdup(list->tetriminos);
		list->tetriminos = ft_emptymap((int)size);
		while (tetris[y])
		{
			x = 0;
			while (tetris[y][x])
			{
				if (tetris[y][x] == list->id)
					list->tetriminos[y][x] = list->id;
				x++;
			}
			y++;
		}
		list = list->next;
	}
}
