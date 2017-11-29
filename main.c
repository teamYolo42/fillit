/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgauther <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 13:49:42 by vgauther          #+#    #+#             */
/*   Updated: 2017/11/29 14:01:17 by vgauther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

char	*ft_read(char *argv)
{
	int fd;
	int ret;
	char buf[BUF_SIZE + 1];

	fd = open((argv), O_RDONLY);
	ret = read(fd, buf, BUF_SIZE);
	buf[ret] = '\0';
	return (ft_strdup(buf));
}

int main(int argc, char **argv)
{
	char *str;
	str = ft_read(argv[1]);
	return 0;
}
