/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgauther <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 15:11:46 by vgauther          #+#    #+#             */
/*   Updated: 2017/11/30 15:42:02 by vgauther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_puttab(char **map)
{
	int x;
	int y;
	char n;

	y = 0;
	n = '\n';
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			ft_putstr(map[y]);
			write(1, &n, 1);
			x++;
		}
		y++;
	}
}

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
	char **map;
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
	map = ft_solve(size, str);
	ft_puttab(map);
	return (0);
}
