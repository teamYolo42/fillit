/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgauther <vgauther@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 13:53:44 by vgauther          #+#    #+#             */
/*   Updated: 2017/11/29 18:20:06 by vgauther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "libft/libft.h"

typedef struct		s_etris
{
	char			**tetriminos;
	int				id;
	struct s_etris	*next;
}					t_etris;

# define BUF_SIZE 1000

int		ft_error(char *str);
char	**ft_emptymap(int size);
char	ft_last_char(char *str);

#endif
