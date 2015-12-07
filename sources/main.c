/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rclanget <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/21 20:16:25 by rclanget          #+#    #+#             */
/*   Updated: 2015/07/21 20:18:39 by rclanget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_map	*parseur(char *line, t_map *map)
{
	char		**coor;
	int			x;
	static int	y = 0;

	coor = ft_strsplit(line, ' ');
	x = 0;
	while (coor[x] && (map = add_elem(x, y, (float)ft_atoi(coor[x]), map)))
		free(coor[x++]);
	free(coor);
	y++;
	return (map);
}

int		add_backsn(char *file)
{
	int fd;
	int save_ss;

	save_ss = dup(1);
	fd = open(file, O_APPEND | O_RDWR);
	if (fd == -1)
		return (0);
	dup2(fd, 1);
	ft_putstr("\n");
	dup2(save_ss, 1);
	close(fd);
	return (1);
}

void	go_print(t_map *map)
{
	void	*mlx;
	void	*win;

	mlx = mlx_init();
	map->relief = RELIEF;
	win = mlx_new_window(mlx, 1000, 700, "42");
	map = reverse_lst(map);
	map = link_down(map);
	map = add_ptm(map, map->relief);
	print_map(map, mlx, win);
	map->win = win;
	map->mlx = mlx;
	map->pos_x = 0;
	map->pos_y = 0;
	mlx_key_hook(win, key_hook, map);
	mlx_loop(mlx);
}

int		main(int ac, char **av)
{
	int		fd;
	char	*line;
	t_map	*map;
	int		i;

	map = NULL;
	if (ac == 2 && add_backsn(av[1]))
	{
		fd = open(av[1], O_RDONLY);
		while ((i = get_next_line(fd, &line)))
		{
			if (i == 0 || i == -1)
				break ;
			map = parseur(line, map);
			free(line);
		}
		go_print(map);
	}
	else
		write(1, "Erreur\n", 7);
	return (0);
}
