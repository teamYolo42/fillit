/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgauther <vgauther@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 14:42:47 by vgauther          #+#    #+#             */
/*   Updated: 2017/11/29 17:17:02 by vgauther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		score_diese(char *str, int i, int x, int v)
{
	if (str[i - 1] == '#' && v - 1 >= 0)
		x++;
	if (str[i + 1] == '#' && v + 1 < 21)
		x++;
	if (str[i - 5] == '#' && v - 5 >= 0)
		x++;
	if (str[i + 5] == '#' && v + 5 < 21)
		x++;
	return (x);
}

int		tetri_is_good(char *str)
{
	int i;
	int v;
	int x;

	x = 0;
	i = 0;
	while (str[i])
	{
		v = 0;
		while (v != 21)
		{
			if (str[i] == '#')
				x = score_diese(str, i, x, v);
			v++;
			i++;
		}
		if (x != 6 && x != 8)
			return (0);
		x = 0;
		if (str[i - 1] == '\0')
			i--;
	}
	return (1);
}

int		pb_de_taille(char *str)
{
	int x;
	int i;
	int v;

	x = 0;
	i = 0;
	while (str[i])
	{
		v = 0;
		while (v < 21)
		{
			if (str[i] == '\n' || str[i] == '\0')
				x++;
			v++;
			i++;
		}
		if (str[i] == '\n')
			return (0);
		if (x != 5)
			return (0);
		x = 0;
		if (str[i - 1] == '\0')
			i--;
	}
	return (1);
}

int		trop_de_diese(char *str)
{
	int i;
	int j;
	int x;

	i = 0;
	x = 0;
	while (str[i])
	{
		j = 0;
		while (j < 21)
		{
			if (str[i] == '#')
				x++;
			j++;
			i++;
		}
		if (x != 4)
			return (0);
		x = 0;
		if (str[i - 1] == 0)
			i--;
	}
	if (str[i - 1] == '\n' && str[i - 2] == '\n')
		return (0);
	return (1);
}

int		ft_error(char *str)
{
	int i;

	i = 0;
	if (str[0] == 0)
		return (0);
	while (str[i])
	{
		if (str[i] != '\n' && str[i] != '\0' && str[i] != '.' && str[i] != '#')
			return (0);
		i++;
	}
	return (pb_de_taille(str) & trop_de_diese(str) & tetri_is_good(str));
}
