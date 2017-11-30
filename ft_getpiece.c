/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getpiece.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcartau <pcartau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 18:32:50 by pcartau           #+#    #+#             */
/*   Updated: 2017/11/30 16:46:19 by asandolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tetri	*addlink(t_tetri *tetri, char **str, char lastchar, int i)
{
	int		k;
	int		j;
	t_tetri *tmp;

	j = i + 4;
	if (!(tmp = malloc(sizeof(t_tetri))))
		return (NULL);
	if (tmp)
	{
		k = 0;
		while (i < j)
		{
			printf("k = %d i = %d\n", k, i);
			tmp->map[k] = str[i];
			k++;
			i++;
		}
		tmp->id = lastchar;
		tmp->next = tetri;
	}
	return (tmp);
}

t_tetri	*place_tetris(char **str, char lastchar)
{
	int		i;
	t_tetri	*tetri;

	tetri = NULL;
	i = 0;
	while (lastchar >= 'A')
	{
		tetri = addlink(tetri, str, lastchar, i);
		i += 4;
		lastchar--;
	}
	return (tetri);
}

int		split(char **tetri, char *str, int i, int k)
{
	int l;

	if (!(tetri[k] = malloc(sizeof(char) * 5)))
		return (0);
	l = 0;
	while (l < 4)
	{
		tetri[k][l] = str[i];
		l++;
		i++;
	}
	tetri[k][l] = '\0';
	return (i);
}

t_tetri	*ft_getpiece(char *str, char lastchar)
{
	int i;
	int k;
	char **tetri;

	i = 0;
	k = 0;
	if (!(tetri = (char **)malloc(sizeof(char *) * ((lastchar - 'A' + 1) * 4) + 1)))
		return (NULL);
	while (str[i])
	{
		if (str[i - 1] == '\n' && str[i] == '\n')
			i++;
		i = split(tetri, str, i, k);
		k++;
		i++;
	}
	tetri[k] = 0;
	return(place_tetris(tetri, lastchar));
}
/*
int main(void)
{
	char str[] = "AAAA\n....\n....\n....\n\n..BB\n..BB\n....\n....\n";
	char **tmp;
	int i;
	int j;

	i = 0;
	ft_getpiece(str,'B');
	return 0;
}
*/
