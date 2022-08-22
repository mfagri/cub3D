/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfagri <mfagri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 22:49:14 by mmardi            #+#    #+#             */
/*   Updated: 2022/07/31 16:41:38 by mfagri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	fill_buffer2(t_rend *m, char **str)
{
	int	y;
	int	x;
	int	i;

	i = 0;
	x = -1;
	while (i < 4)
	{
		m->wall = mlx_xpm_file_to_image(m->mlx, str[i], &m->width, &m->height);
		m->textter->addr = mlx_get_data_addr(m->wall, &m->textter->bits, \
		&m->textter->line, &m->textter->endian);
		y = -1;
		while (++y < 64)
		{
			x = -1;
			while (++x < 64)
			{
				m->textter->dst = m->textter->addr + \
				(y * m->textter->line + x * (m->textter->bits / 8));
				m->buffer[i][(64 * y) + x] = *(unsigned int *)m->textter->dst;
			}
		}
		i++;
	}
}

void	fill_buffer(t_rend *m)
{
	char	**str;

	str = malloc(sizeof(char *) * 5);
	if (!str)
		ft_allocation_err();
	str[1] = m->textter->ea;
	str[0] = m->textter->we;
	str[2] = m->textter->no;
	str[3] = m->textter->so;
	str[4] = NULL;
	fill_buffer2(m, str);
	ft_free(NULL, str);
}

void	put_wall(t_rend *m, int wall_h, int i, int c)
{
	t_img	img;
	int		y;
	int		x;

	img.img = mlx_new_image(m->mlx, 2, wall_h);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	new_x_y(&img, m, i);
	y = 0;
	while (y != wall_h)
	{
		x = 0;
		img.newy = ((y) * ((float)WALL_SIZE / (float)wall_h));
		while (x != 2)
		{
			img.dst = img.addr + (y * img.line_length + x * (img.bits_per_pixel
						/ 8));
			*(unsigned int *)img.dst = m->buffer[c][(64 * img.newy) + img.newx];
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(m->mlx, m->mlx_win, img.img, i, \
		(480 / 2) - (wall_h / 2));
	mlx_destroy_image(m->mlx, img.img);
}

int	chack_wall_side(t_rend *m, int i)
{
	int	c;

	c = 0;
	if (m->rays[i].washitvertical)
	{
		if (m->rays[i].is_facingleft)
			c = 0;
		else if ((m->rays[i].is_facingright))
			c = 1;
	}
	else
	{
		if (m->rays[i].is_faceingup)
			c = 2;
		else if (m->rays[i].is_facingdown)
			c = 3;
	}
	return (c);
}

void	projectewall3d(t_rend *m)
{
	int		i;
	int		c;
	float	wallstripheigth;
	float	distanceprojplan;

	i = 0;
	distanceprojplan = (640 / 2) / tan(FOV_ANGLE / 2);
	while (i < NUM_RAYS)
	{
		m->raydist = m->rays[i].distane * cos(m->rays[i].ray_angle
				- m->pplayer->rotatangle);
		wallstripheigth = (WALL_SIZE / m->raydist) * distanceprojplan;
		c = chack_wall_side(m, i);
		put_wall(m, (int)fabs((wallstripheigth)), i * 2, c);
		i++;
	}
}
