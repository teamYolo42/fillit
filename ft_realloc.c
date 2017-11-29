/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcartau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 14:12:37 by pcartau           #+#    #+#             */
/*   Updated: 2017/11/29 15:26:34 by pcartau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

static inline int len(void *ptr)
{
	unsigned char *tmp;
	int	i;

	i= 0;
	tmp = (unsigned char *)ptr;
	while (tmp[i])
		i++;
	return (i);
}

void		*ft_realloc(void *ptr, size_t size)
{
	int i;
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
