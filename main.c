/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgauther <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 15:11:46 by vgauther          #+#    #+#             */
/*   Updated: 2017/11/30 14:30:38 by vgauther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*ft_read(char *argv)
{
	int		fd;
	int		ret;
	char	buf[BUF_SIZE + 1];

	fd = open((argv), O_RDONLY);
	ret = read(fd, buf, BUF_SIZE);
	buf[ret] = '\0';
	return (ft_strdup(buf));
}

int		main(int argc, char **argv)
{
	char	*str;
	int		size;

	size = 0;
	if (argc != 2)
	{
		ft_putstr("./fillit [input a single fillit file]\n");
		return (0);
	}
	str = ft_read(argv[1]);
	if (ft_error(str) == 0)
	{
		ft_putstr("error\n");
		return (0);
	}
	size = count_map_min(str);
	ft_solve(size, str);
	return (0);
}
