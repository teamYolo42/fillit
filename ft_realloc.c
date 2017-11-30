/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcartau <pcartau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 14:12:37 by pcartau           #+#    #+#             */
/*   Updated: 2017/11/30 15:15:12 by vgauther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void				*ft_realloc(void *ptr, size_t size)
{
	void	*dest;

	if (ptr)
	{
		dest = malloc(sizeof(void) * size);
		dest = ft_memcpy(dest, ptr, size);
		free(ptr);
		return (dest);
	}
	if (!(ptr = malloc(sizeof(void) * size)))
		return (NULL);
	return (ptr);
}
