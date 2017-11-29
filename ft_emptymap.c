/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_emptymap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcartau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 19:18:02 by pcartau           #+#    #+#             */
/*   Updated: 2017/11/29 14:31:07 by vgauther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

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
