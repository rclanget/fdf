/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rclanget <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/21 20:08:48 by rclanget          #+#    #+#             */
/*   Updated: 2015/07/21 20:09:57 by rclanget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_pt	*calc_iso(t_pt *pt, int relief)
{
	t_pt *new_pt;

	new_pt = (t_pt *)ft_memalloc(sizeof(t_pt));
	new_pt->x = (CTE1 * pt->x) - (CTE2 * pt->y);
	new_pt->y = (pt->z * relief) + ((CTE1 / 2) * pt->x) + ((CTE2 / 2) * pt->y);
	return (new_pt);
}

t_map	*add_ptm(t_map *map, int relief)
{
	t_map *tmp_map;

	tmp_map = map;
	while (tmp_map && (tmp_map->vect3m = calc_iso(tmp_map->vect3l, relief)))
		tmp_map = tmp_map->next;
	return (map);
}

double	*set_tab_coor(t_map *map, int decb, int decd, int coef)
{
	double *tmp_coor;

	tmp_coor = (double *)ft_memalloc(sizeof(double) * 9);
	tmp_coor[0] = (map->vect3m->x + decd) * coef;
	tmp_coor[1] = (map->vect3m->y + decb) * coef;
	tmp_coor[2] = (double)map->vect3l->z;
	tmp_coor[3] = map->next ? ((map->next->vect3m->x + decd) * coef) : 0;
	tmp_coor[4] = map->next ? (map->next->vect3m->y + decb) * coef : 0;
	tmp_coor[5] = map->next ? (double)map->next->vect3m->z : 0;
	tmp_coor[6] = map->down ? ((map->down->vect3m->x + decd) * coef) : 0;
	tmp_coor[7] = map->down ? (map->down->vect3m->y + decb) * coef : 0;
	tmp_coor[8] = map->down ? (double)map->down->vect3m->z : 0;
	return (tmp_coor);
}
