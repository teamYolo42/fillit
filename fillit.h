/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgauther <vgauther@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 13:53:44 by vgauther          #+#    #+#             */
/*   Updated: 2017/11/30 15:33:30 by vgauther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <stdlib.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "libft/libft.h"

/*typedef struct	s_etris
{
	char			**tetriminos;
	int				id;
	struct s_etris	*next;
}				t_etris;
*/
typedef struct	s_variable
{
	char		**map;
	char		**tetri;
	char		**tmp_tetri;
}				t_variable;

typedef struct	s_tetri
{
	char			id;
	char			**map;
	struct s_tetri	*next;
}				t_tetri;

# define BUF_SIZE 1000

int				ft_error(char *str);
char			**ft_emptymap(int size);
char			ft_last_char(char *str);
int				ft_right(char **tetris, char c);
int				ft_bottom(char **tetris, char c);
char			**ft_dupdup(char **src);
int				ft_is_placed(char **map, int num);
char			*ft_config(int indice, char *plaque, long n_config, int *tab);
char			*ft_first_comb(char c);
void			ft_change_size(t_tetri *list, size_t size);
int				count_map_min(char *str);
char			**ft_solve(int size, char *str);
t_tetri			*ft_getpiece(char *str, char lastchar);

#endif
