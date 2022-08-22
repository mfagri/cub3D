/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_creation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfagri <mfagri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 21:33:58 by mfagri            #+#    #+#             */
/*   Updated: 2022/07/31 17:21:39 by mfagri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	draw_square(int x, int y, char c, t_img *img)
{
	int	i;
	int	j;
	int	color;

	if (c == '0')
		color = 0xffffff;
	else if (c == '1')
		color = 0x000000;
	else if (c == 'p')
		color = 0xff3300;
	j = y;
	while (j < y + MINIMAP_SIZE)
	{
		i = x;
		while (i < x + MINIMAP_SIZE)
		{
			set_screen_pixel(img, i, j, color);
			i++;
		}
		j++;
	}
}

void	img_map(t_rend *m)
{
	t_img			img;
	int				i;
	int				j;
	int				k;

	i = 100 / m->mapx;
	img.img = mlx_new_image(m->mlx, m->mapx * MINIMAP_SIZE, lines(m->map)
			* MINIMAP_SIZE);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	j = 0;
	k = 0;
	while (m->map[j])
	{
		k = -1;
		while (m->map[j][++k])
			draw_square(k * MINIMAP_SIZE, j * MINIMAP_SIZE, \
			m->map[j][k], &img);
		j++;
	}
	draw_square((int)floor(m->pplayer->x / WALL_SIZE) * MINIMAP_SIZE, \
	(int)floor(m->pplayer->y / WALL_SIZE) * MINIMAP_SIZE, 'p', &img);
	mlx_put_image_to_window(m->mlx, m->mlx_win, img.img, 0, 0);
	mlx_destroy_image(m->mlx, img.img);
}

int	image_rendering(t_rend *game)
{
	player_rendering(game);
	floor_and_ceilling(game, 0, create_rgb(game->colors->c[0], \
	game->colors->c[1], game->colors->c[2]));
	floor_and_ceilling(game, 1, create_rgb(game->colors->f[0], \
	game->colors->f[1], game->colors->f[2]));
	rays(game);
	projectewall3d(game);
	img_map(game);
	return (0);
}

void	player_init(t_rend *m)
{
	m->key_a = 0;
	m->key_d = 0;
	m->key_s = 0;
	m->key_w = 0;
	m->key_left = 0;
	m->key_right = 0;
	m->pplayer = malloc(sizeof(t_player));
	if (!m->pplayer)
		ft_allocation_err();
	get_index(m, &m->pplayer->x, &m->pplayer->y);
	m->pplayer->x *= WALL_SIZE;
	m->pplayer->y *= WALL_SIZE;
	m->pplayer->turn_d = 0;
	m->pplayer->wlk_d = 0;
	if (m->player == 'N')
		m->pplayer->rotatangle = 3 * PI / 2;
	if (m->player == 'S')
		m->pplayer->rotatangle = PI / 2;
	if (m->player == 'W')
		m->pplayer->rotatangle = PI;
	if (m->player == 'E')
		m->pplayer->rotatangle = 0;
	m->pplayer->move_speed = 3;
	m->pplayer->rotation_speed = 5 * (PI / 180);
}

void	mlx_start(char **map, t_rend *game)
{
	game->map = final_map(game, map);
	game->mlx = mlx_init();
	game->mlx_win = mlx_new_window(game->mlx, 640, 480, "cub3d");
	fill_buffer(game);
	player_init(game);
	image_rendering(game);
	mlx_hook(game->mlx_win, 2, 0, &key_press, game);
	mlx_hook(game->mlx_win, 3, 0, &key_release, game);
	mlx_hook(game->mlx_win, 6, 0x40, mouse_move, game);
	mlx_hook(game->mlx_win, 17, 0, &ft_exit, game);
	mlx_loop_hook(game->mlx, image_rendering, game);
	mlx_loop(game->mlx);
}
