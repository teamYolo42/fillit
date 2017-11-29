/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tlnew.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebertin <ebertin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 14:47:31 by ebertin           #+#    #+#             */
/*   Updated: 2017/11/25 18:44:20 by asandolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_etris	*ft_tlstnew(void)
{
	t_etris *ret;

	ret = NULL;
	return (ret);
}

t_etris	*ft_tlstadd(t_etris *list, char **tertri, int id)
{
	t_etris *tmp;

	tmp = malloc(sizeof(t_etris));
	if (tmp)
	{
		tmp->tetriminos = tertri;
		tmp->id = id;
		tmp->next = list;
	}
	return (tmp);
}
