/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puttab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asandolo <asandolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 16:27:27 by asandolo          #+#    #+#             */
/*   Updated: 2017/11/15 16:29:54 by asandolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_puttab(char **tab)
{
	size_t i;

	i = 0;
	if (tab)
		while (tab[i])
		{
			ft_putstr(tab[i]);
			ft_putchar('\n');
			i++;
		}
}
