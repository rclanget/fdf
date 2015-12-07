/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_relief_command.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rclanget <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/21 20:11:18 by rclanget          #+#    #+#             */
/*   Updated: 2015/07/21 20:11:32 by rclanget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void ft_keycode_zoom(t_map *map)
{
	map->coef += 1;
	mlx_clear_window(map->mlx, map->win);
	print_map(map, map->mlx, map->win);
}

void ft_keycode_dezoom(t_map *map)
{
	map->coef -= 1;
	mlx_clear_window(map->mlx, map->win);
	print_map(map, map->mlx, map->win);
}

void ft_keycode_reliefp(t_map *map)
{
	map->relief += 1;
	map = add_ptm(map, map->relief);
	mlx_clear_window(map->mlx, map->win);
	print_map(map, map->mlx, map->win);
	free(map->vect3m);
}

void ft_keycode_reliefm(t_map *map)
{
	map->relief -= 1;
	map = add_ptm(map, map->relief);
	mlx_clear_window(map->mlx, map->win);
	print_map(map, map->mlx, map->win);
	free(map->vect3m);
}
