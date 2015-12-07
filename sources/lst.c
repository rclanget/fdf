/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rclanget <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/21 20:11:48 by rclanget          #+#    #+#             */
/*   Updated: 2015/07/21 20:16:06 by rclanget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_map	*find_down(float x, float y, t_map *map)
{
	t_map *tmp_map;

	tmp_map = map;
	while (tmp_map)
	{
		if (tmp_map->vect3l->x == x && tmp_map->vect3l->y == (y + 1))
			return (tmp_map);
		tmp_map = tmp_map->next;
	}
	return (NULL);
}

t_map	*link_down(t_map *map)
{
	t_map	*tmp_map;

	tmp_map = map;
	while (tmp_map)
	{
		tmp_map->down = find_down(tmp_map->vect3l->x,\
		tmp_map->vect3l->y, tmp_map->next);
		tmp_map = tmp_map->next;
	}
	return (map);
}

t_map	*swap_lst(t_map *map1, t_map *map2)
{
	t_pt	*tmp_pt;
	int		tmp_id;

	tmp_id = map2->id;
	tmp_pt = map2->vect3l;
	map2->id = map1->id;
	map2->vect3l = map1->vect3l;
	map1->id = tmp_id;
	map1->vect3l = tmp_pt;
	return (map1);
}

t_map	*reverse_lst(t_map *map)
{
	t_map	*tmp_map;
	int		reverse;

	reverse = 0;
	tmp_map = map;
	while (tmp_map->next)
	{
		if (tmp_map->id > tmp_map->next->id && (reverse = 1))
			tmp_map = swap_lst(tmp_map, tmp_map->next);
		else
			tmp_map = tmp_map->next;
	}
	return (reverse ? reverse_lst(map) : map);
}

t_map	*add_elem(float x, float y, float z, t_map *map)
{
	t_map		*new_map;
	static	int	i;

	new_map = (t_map *)ft_memalloc(sizeof(t_map));
	new_map->vect3l = (t_pt *)ft_memalloc(sizeof(t_pt));
	if (!map)
		new_map->next = NULL;
	else
		new_map->next = map;
	new_map->vect3l->x = x;
	new_map->vect3l->y = y;
	new_map->pos_x = 1;
	new_map->pos_y = 1;
	new_map->vect3l->z = z;
	new_map->coef = 1;
	new_map->down = NULL;
	new_map->id = i++;
	return (new_map);
}
