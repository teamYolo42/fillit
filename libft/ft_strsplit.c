/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asandolo <asandolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 11:54:41 by asandolo          #+#    #+#             */
/*   Updated: 2017/11/15 10:51:37 by asandolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int		ft_feel(char const *s, char **tab, int *tab1, char c)
{
	int j;
	int x;

	j = 0;
	x = tab1[0];
	while (s[tab1[0]] != c && s[tab1[0]])
		tab1[0] += 1;
	if (!(tab[tab1[1]] = (char *)malloc(sizeof(char) * tab1[0] - x + 1)))
		return (0);
	while (x < tab1[0])
	{
		tab[tab1[1]][j] = s[x];
		j++;
		x++;
	}
	tab[tab1[1]][j] = '\0';
	return (tab1[0]);
}

static int		ft_detectword(char const *s, int i, char c)
{
	while (s[i] == c)
		i++;
	return (i);
}

static int		ft_countwords(char const *s, char c)
{
	int word;
	int i;

	i = 0;
	word = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
			word++;
		while (s[i] != c && s[i])
			i++;
	}
	return (word);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		word;
	int		tab1[2];

	if (s)
	{
		tab1[0] = 0;
		tab1[1] = 0;
		word = ft_countwords(s, c);
		if (!(tab = (char **)malloc(sizeof(char *) * word + 1)))
			return (NULL);
		while (s[tab1[0]] && tab1[1] < word)
		{
			tab1[0] = ft_detectword(s, tab1[0], c);
			if (!(tab1[0] = ft_feel(s, tab, tab1, c)))
				return (NULL);
			tab1[1] += 1;
		}
		tab[tab1[1]] = NULL;
		return (tab);
	}
	return (NULL);
}
