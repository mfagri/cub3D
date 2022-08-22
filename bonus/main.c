/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfagri <mfagri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 19:06:49 by mfagri            #+#    #+#             */
/*   Updated: 2022/08/15 19:10:16 by mfagri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_allocation_err(void)
{
	write(2, "error in allocation\n", 20);
	exit(1);
}

int	ft_exit(t_rend *m)
{
	write(1, "You Quit !\n", 12);
	ft_free(NULL, m->map);
	free(m->textter);
	free(m->colors);
	exit(0);
	return (0);
}

int	main(int ac, char **av)
{
	int		fd;
	char	**map;
	t_rend	game;

	if (ac != 2)
	{
		printf("Error\n2 Arguments Needed\n");
		exit (1);
	}
	check_extension(av[1]);
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		return (printf("File not Found\n"), close(fd), 1);
	map = map_filling(fd);
	if (!map_final_check(map, &game))
	{
		game.rays = malloc(sizeof(t_ray) * NUM_RAYS);
		if (!game.rays)
			ft_allocation_err();
		mlx_start(map, &game);
	}
	return (0);
}
