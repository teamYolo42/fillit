/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgauther <vgauther@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 18:13:51 by vgauther          #+#    #+#             */
/*   Updated: 2017/11/30 19:16:04 by pcartau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		count_map_min(char *str)
{
	int nbr_de_diese;
	int i;
	int size;

	nbr_de_diese = 0;
	size = 2;
	i = 0;
	while (str[i])
	{
		if (str[i] == '#')
			nbr_de_diese++;
		i++;
	}
	while ((size * size) < nbr_de_diese)
		size++;
	return (size);
}

/*
** ft_dupdup = strdup pour un char **
*/

char	**ft_dupdup(char **src)
{
	int		i;
	char	**dst;

	i = 0;
	while (src[i])
		i++;
	if (!(dst = (char **)malloc(sizeof(char *) * (i + 1))))
		return (NULL);
	i = 0;
	while (src[i])
	{
		dst[i] = ft_strdup(src[i]);
		i++;
	}
	return (dst);
}

int		ft_is_placed(char **map, int num)
{
	int x;
	int y;
	int nbr;

	y = 0;
	nbr = 1;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (ft_isalpha(map[y][x]))
				nbr++;
			x++;
		}
		y++;
	}
	if (num * 4 != nbr)
		return (0);
	return (1);
}

char	*ft_first_comb(char c)
{
	int		i;
	int		nbr;
	char	*first_comb;

	i = 0;
	nbr = c - 'A' + 1;
	if (!(first_comb = (char *)malloc(sizeof(char) * nbr + 1)))
		return (NULL);
	while (i < nbr)
	{
		first_comb[i] = c - nbr + 1;
		i++;
		c++;
	}
	first_comb[i] = '\0';
	return (first_comb);
}

char	ft_last_char(char *str)
{
	int i;

	i = ft_strlen(str);
	i--;
	while (str[i] == '.' || str[i] == '\n')
		i--;
	return (str[i]);
}
