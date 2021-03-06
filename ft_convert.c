/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgauther <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 16:44:20 by vgauther          #+#    #+#             */
/*   Updated: 2017/11/27 15:42:16 by vgauther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_convert(char *str)
{
	int i;
	int c;
	int num;

	i = 0;
	num = 1;
	c = 'A';
	while (str[i])
	{
		if (str[i] == '#')
		{
			str[i] = c;
			num++;
		}
		if (num == 5)
		{
			c++;
			num = 1;
		}
		i++;
		if (str[i] != '\n' && str[i] != '.' && str[i] <= 'A' && str[i] >= 'Z')
			str[i] = '\0';
	}
	return (str);
}
