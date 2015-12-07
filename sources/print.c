/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rclanget <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/21 20:19:09 by rclanget          #+#    #+#             */
/*   Updated: 2015/07/21 20:25:30 by rclanget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		color_gradient(double z)
{
	if (z <= -10)
		return (0x00001047);
	else if (z <= -8)
		return (0x000F2268);
	else if (z <= -6)
		return (0x001A2974);
	else if (z <= -4)
		return (0x0025307F);
	else if (z <= -2)
		return (0x002A3485);
	else if (z <= -1)
		return (0x00353B91);
	else if (z <= 0)
		return (0x003B3F97);
	else if (z <= 1)
		return (0x003B3F97);
	else if (z <= 3)
		return (0x006164AA);
	else if (z <= 6)
		return (0x009A9CC8);
	else if (z <= 8)
		return (0x00D3D4E6);
	else
		return (0x00FFFFFF);
}

void	print_elem1(int *calcoor, double *coor, void *mlx, void *win)
{
	calcoor[6] = calcoor[0] / 2;
	while (calcoor[7] <= calcoor[0])
	{
		calcoor[4] += calcoor[2];
		calcoor[6] += calcoor[1];
		if (calcoor[6] >= calcoor[0])
		{
			calcoor[6] -= calcoor[0];
			calcoor[5] += calcoor[3];
		}
		mlx_pixel_put(mlx, win, calcoor[4], calcoor[5],\
		color_gradient(coor[2]));
		calcoor[7]++;
	}
}

void	print_elem2(int *calcoor, double *coor, void *mlx, void *win)
{
	calcoor[6] = calcoor[1] / 2;
	while (calcoor[7] <= calcoor[1])
	{
		calcoor[5] += calcoor[3];
		calcoor[6] += calcoor[0];
		if (calcoor[6] >= calcoor[1])
		{
			calcoor[6] -= calcoor[1];
			calcoor[4] += calcoor[2];
		}
		mlx_pixel_put(mlx, win, calcoor[4], calcoor[5],\
		color_gradient(coor[2]));
		calcoor[7]++;
	}
}

void	print_ligne2(double *coor, void *mlx, void *win, int act)
{
	int *calcoor;

	if (act && (coor[3] = coor[6]))
		coor[4] = coor[7];
	calcoor = (int *)ft_memalloc(sizeof(int) * 8);
	calcoor[7] = 1;
	calcoor[4] = coor[0];
	calcoor[5] = coor[1];
	calcoor[0] = coor[3] - coor[0];
	calcoor[1] = coor[4] - coor[1];
	calcoor[2] = (calcoor[0] > 0) ? 1 : -1;
	calcoor[3] = (calcoor[1] > 0) ? 1 : -1;
	calcoor[0] = abs(calcoor[0]);
	calcoor[1] = abs(calcoor[1]);
	mlx_pixel_put(mlx, win, calcoor[4], calcoor[5], color_gradient(coor[2]));
	if (calcoor[0] > calcoor[1])
		print_elem1(calcoor, coor, mlx, win);
	else
		print_elem2(calcoor, coor, mlx, win);
}

void	print_map(t_map *map, void *mlx, void *win)
{
	double	*coor;
	t_map	*tmp_map;
	int		decb;
	int		decd;

	tmp_map = map;
	decb = map->pos_x;
	decd = map->pos_y;
	while (tmp_map)
	{
		coor = set_tab_coor(tmp_map, decb, decd, map->coef);
		if (tmp_map->next && tmp_map->vect3m->x < tmp_map->next->vect3m->x)
			print_ligne2(coor, mlx, win, 0);
		if (tmp_map->down)
			print_ligne2(coor, mlx, win, 1);
		tmp_map = tmp_map->next;
		free(coor);
	}
}
