/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_background.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmardi <mmardi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 18:55:12 by mmardi            #+#    #+#             */
/*   Updated: 2022/07/29 19:32:27 by mmardi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	set_screen_pixel(t_img *screen, int i, int j, int color)
{
	char	*ptr;

	ptr = screen->addr + j * screen->line_length + i * (screen->bits_per_pixel
			/ 8);
	*(unsigned int *)ptr = color;
}

void	floor_and_ceilling(t_rend *m, int i, int c)
{
	t_img	img;
	int		y;

	if (i == 0)
		y = 0;
	else
		y = 480 / 2;
	img.img = mlx_new_image(m->mlx, 640, 480 / 2);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	m->i = -1;
	while (++m->i != 480 / 2)
	{
		m->j = -1;
		while (++m->j != 640)
			set_screen_pixel(&img, m->j, m->i, c);
	}
	mlx_put_image_to_window(m->mlx, m->mlx_win, img.img, 0, y);
	mlx_destroy_image(m->mlx, img.img);
}
