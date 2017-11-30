/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getpiece.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asandolo <asandolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 17:37:21 by asandolo          #+#    #+#             */
/*   Updated: 2017/11/30 17:37:22 by asandolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tetri		*addlink(t_tetri *tetri, char **str, char lastchar, int i)
{
	int		k;
	int		j;
	t_tetri *tmp;

	j = i + 4;
	if (!(tmp = malloc(sizeof(t_tetri))))
		return (NULL);
	if (tmp)
	{
		if (!(tmp->map = malloc(sizeof(char *) * 17)))
			return (NULL);
		k = 0;
		while (i < j)
			tmp->map[k++] = str[i++];
		tmp->id = lastchar;
		tmp->next = tetri;
	}
	return (tmp);
}

t_tetri		*place_tetris(char **str, char lastchar)
{
	int		i;
	t_tetri *tetri;

	tetri = NULL;
	i = 0;
	while (lastchar >= 'A')
	{
		tetri = addlink(tetri, str, lastchar, i);
		i += 4;
		lastchar--;
	}
	return (tetri);
}

int			split(char **tetri, char *str, int i, int k)
{
	int l;

	if (!(tetri[k] = malloc(sizeof(char) * 5)))
		return (0);
	l = 0;
	while (l < 4)
	{
		tetri[k][l] = str[i];
		l++;
		i++;
	}
	tetri[k][l] = '\0';
	return (i);
}

t_tetri		*ft_getpiece(char *str, char lc)
{
	int		i;
	int		k;
	char	**tetri;

	i = 0;
	k = 0;
	if (!(tetri = (char **)malloc(sizeof(char *) * ((lc - 'A' + 1) * 4) + 1)))
		return (NULL);
	while (str[i])
	{
		if (str[i - 1] == '\n' && str[i] == '\n')
			i++;
		i = split(tetri, str, i, k);
		k++;
		i++;
	}
	tetri[k] = 0;
	return (place_tetris(tetri, lc));
}
