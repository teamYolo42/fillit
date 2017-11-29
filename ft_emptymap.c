/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_emptymap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcartau <pcartau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 19:18:02 by pcartau           #+#    #+#             */
/*   Updated: 2017/11/29 14:48:08 by asandolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*ft_emptymap(int i, int j)
{
	char	*map;
	int		k;
	int		l;

	l = i;
	i = (i * j) + (j + 1);
	map = (char *)malloc(sizeof(char) * i + 1);
	j = 0;
	k = 0;
	while (j < i - 1)
	{
		k++;
		if (k == l + 1)
		{
			map[j] = '\n';
			k = 0;
		}
		else
			map[j] = '.';
		j++;
	}
	map[j] = '\n';
	map[j + 1] = '\0';
	return (map);
}
