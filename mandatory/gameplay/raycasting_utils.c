/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfagri <mfagri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 22:50:31 by mfagri            #+#    #+#             */
/*   Updated: 2022/07/29 22:35:30 by mfagri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

float	normaliseangle(float angle)
{
	angle = remainder(angle, (2 * PI));
	if (angle < 0)
		angle = (2 * PI) + angle;
	return (angle);
}

float	distancebetwenpoint(float x1, float y1, float x2, float y2)
{
	return (sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)));
}

int	is_end_window(t_rend *m, double x, double y)
{
	if (x < 0 || x >= m->mapx * WALL_SIZE
		|| y < 0 || y >= lines(m->map) * WALL_SIZE)
		return (TRUE);
	return (FALSE);
}

int	is_wall(t_rend *m, int x, int y, char identf)
{
	int	grid_x;
	int	grid_y;

	if (is_end_window(m, x, y))
		return (TRUE);
	grid_x = floor(x / WALL_SIZE);
	grid_y = floor(y / WALL_SIZE);
	if (grid_x >= m->mapx || grid_y >= lines(m->map))
		return (TRUE);
	if (m->map[grid_y][grid_x] == identf)
		return (TRUE);
	return (FALSE);
}

void	ft_init_caster(t_rend *m)
{
	m->caster = malloc(sizeof(t_caster));
	if (!m->caster)
		ft_allocation_err();
	m->caster->distance = 0;
	m->caster->wallhitx = 0;
	m->caster->wallhity = 0;
	m->caster->hhitx = 0;
	m->caster->hhity = 0;
	m->caster->vhitx = 0;
	m->caster->vhity = 0;
	m->caster->x_chk = 0;
	m->caster->y_chk = 0;
	m->caster->xstep = 0;
	m->caster->ystep = 0;
	m->caster->xintercept = 0;
	m->caster->yintercept = 0;
	m->caster->findhorzwall_hit = 0;
	m->caster->findvir_wall = 0;
	m->caster->rayisup = 0;
	m->caster->rayisdown = 0;
	m->caster->rayisleft = 0;
	m->caster->rayisright = 0;
	m->caster->vx_chk = 0;
	m->caster->vy_chk = 0;
}
