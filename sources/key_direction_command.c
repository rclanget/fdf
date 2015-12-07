/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_direction_command.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rclanget <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/21 20:10:10 by rclanget          #+#    #+#             */
/*   Updated: 2015/07/21 20:10:51 by rclanget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_keycode_up(t_map *map)
{
	map->pos_x -= 20;
	mlx_clear_window(map->mlx, map->win);
	print_map(map, map->mlx, map->win);
}

void		ft_keycode_down(t_map *map)
{
	map->pos_x += 20;
	mlx_clear_window(map->mlx, map->win);
	print_map(map, map->mlx, map->win);
}

void		ft_keycode_right(t_map *map)
{
	map->pos_y += 20;
	mlx_clear_window(map->mlx, map->win);
	print_map(map, map->mlx, map->win);
}

void		ft_keycode_left(t_map *map)
{
	map->pos_y -= 20;
	mlx_clear_window(map->mlx, map->win);
	print_map(map, map->mlx, map->win);
}

int			key_hook(int keycode, t_map *b)
{
	if (keycode == 53)
	{
		mlx_destroy_window(b->mlx, b->win);
		exit(0);
	}
	if (keycode == 125)
		ft_keycode_down(b);
	else if (keycode == 126)
		ft_keycode_up(b);
	else if (keycode == 123)
		ft_keycode_left(b);
	else if (keycode == 124)
		ft_keycode_right(b);
	else if (keycode == 69)
		ft_keycode_zoom(b);
	else if (keycode == 78)
		ft_keycode_dezoom(b);
	else if (keycode == 121)
		ft_keycode_reliefp(b);
	else if (keycode == 116)
		ft_keycode_reliefm(b);
	return (0);
}
