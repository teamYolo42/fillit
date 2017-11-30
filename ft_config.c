/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_config.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcartau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 09:34:26 by pcartau           #+#    #+#             */
/*   Updated: 2017/11/30 15:13:15 by vgauther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	swap(char mem, int indice, int i, char *plaque)
{
	mem = plaque[indice];
	plaque[indice] = plaque[i];
	plaque[i] = mem;
}

int		test(long it, long n_config)
{
	if (it == n_config)
		return (1);
	return (0);
}

char	*ft_config(int indice, char *plaque, long n_config, int *tab)
{
	int		i;
	char	mem;

	mem = 0;
	if (indice == (tab[0] - 1))
	{
		tab[1] = test(tab[2], n_config);
		tab[2]++;
	}
	i = indice;
	while (i < tab[0])
	{
		swap(mem, indice, i, plaque);
		ft_config(indice + 1, plaque, n_config, tab);
		if (tab[1])
			return (plaque);
		swap(mem, indice, i, plaque);
		i++;
	}
	return (0);
}
