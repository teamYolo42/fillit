/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgauther <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 18:13:51 by vgauther          #+#    #+#             */
/*   Updated: 2017/11/29 17:54:35 by vgauther         ###   ########.fr       */
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
