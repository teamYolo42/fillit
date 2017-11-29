/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgauther <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 14:42:47 by vgauther          #+#    #+#             */
/*   Updated: 2017/11/29 14:51:03 by vgauther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

int ft_error(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '\n' && str[i] != '\0' && str[i] != '.' && str[i] != '#')
			return(0);
		i++;
	}
	return (1);
}
