/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rclanget <rclanget@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/09 18:16:34 by rclanget          #+#    #+#             */
/*   Updated: 2015/07/21 21:02:26 by rclanget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "libft.h"

# define CTE1 10
# define CTE2 10
# define RELIEF -1

typedef struct		s_pt
{
	float			x;
	float			y;
	float			z;
}					t_pt;

typedef struct		s_map
{
	int				id;
	t_pt			*vect3l;
	t_pt			*vect3m;
	int				pos_x;
	int				pos_y;
	int				coef;
	int				relief;
	void			*mlx;
	void			*win;
	struct s_map	*next;
	struct s_map	*down;
}					t_map;

void				print_ligne(double *coor, void *mlx, void *win);
void				print_ligne2(double *coor, void *mlx, void *win, int act);
void				ft_keycode_up(t_map *map);
void				ft_keycode_down(t_map *map);
void				ft_keycode_right(t_map *map);
void				ft_keycode_left(t_map *map);
void				ft_keycode_zoom(t_map *map);
void				ft_keycode_dezoom(t_map *map);
void				ft_keycode_reliefp(t_map *map);
void				ft_keycode_reliefm(t_map *map);
void				print_map(t_map *map, void *mlx, void *win);
t_map				*add_ptm(t_map *map, int relief);
double				*set_tab_coor(t_map *map, int decb, int decd, int coef);
t_map				*link_down(t_map *map);
t_map				*reverse_lst(t_map *map);
t_map				*add_elem(float x, float y, float z, t_map *map);
void				ft_keycode_zoom(t_map *map);
void				ft_keycode_dezoom(t_map *map);
void				ft_keycode_reliefp(t_map *map);
void				ft_keycode_reliefm(t_map *map);
int					key_hook(int keycode, t_map *b);

#endif
