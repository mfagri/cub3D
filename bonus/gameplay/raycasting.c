/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfagri <mfagri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 20:34:27 by mfagri            #+#    #+#             */
/*   Updated: 2022/07/31 16:20:55 by mfagri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_ray_distance(t_rend *m, int i)
{
	if (m->caster->findhorzwall_hit)
		m->caster->horz_dist = distancebetwenpoint(m->pplayer->x, \
		m->pplayer->y, m->caster->x_chk, m->caster->y_chk);
	else
		m->caster->horz_dist = INT_MAX;
	if (m->caster->findvir_wall)
		m->caster->vert_dist = distancebetwenpoint(m->pplayer->x, \
		m->pplayer->y, m->caster->vx_chk, m->caster->vy_chk);
	else
		m->caster->vert_dist = INT_MAX;
	if (m->caster->horz_dist <= m->caster->vert_dist)
	{
		m->caster->wallhitx = m->caster->x_chk;
		m->caster->wallhity = m->caster->y_chk;
	}
	else
	{
		m->caster->wallhitx = m->caster->vx_chk;
		m->caster->wallhity = m->caster->vy_chk;
	}
	m->rays[i].wallhitx = m->caster->wallhitx;
	m->rays[i].wallhity = m->caster->wallhity;
}

void	cast_singleray(float rayangel, int i, t_rend *m)
{
	ft_init_caster(m);
	rayangel = normaliseangle(rayangel);
	m->rays[i].ray_angle = rayangel;
	m->rays[i].washitvertical = FALSE;
	m->caster->vert_dist = 0;
	m->caster->horz_dist = 0;
	if (rayangel > 0 && rayangel < PI)
		m->caster->rayisdown = 1;
	m->caster->rayisup = !m->caster->rayisdown;
	if (rayangel < 0.5 * PI || rayangel > 1.5 * PI)
		m->caster->rayisright = 1;
	m->caster->rayisleft = !m->caster->rayisright;
	horizontal_ray(m, rayangel);
	vertical_ray(m, rayangel);
	ft_ray_distance(m, i);
	if (m->caster->horz_dist <= m->caster->vert_dist)
		m->rays[i].distane = m->caster->horz_dist;
	else
		m->rays[i].distane = m->caster->vert_dist;
	if ((m->caster->vert_dist < m->caster->horz_dist))
		m->rays[i].washitvertical = TRUE;
	m->rays[i].is_faceingup = m->caster->rayisup;
	m->rays[i].is_facingdown = m->caster->rayisdown;
	m->rays[i].is_facingleft = m->caster->rayisleft;
	m->rays[i].is_facingright = m->caster->rayisright;
}

void	rays(t_rend *m)
{
	int		colum;
	float	ra;
	int		i;

	colum = 0;
	i = 0;
	ra = m->pplayer->rotatangle - (FOV_ANGLE / 2);
	while (i < NUM_RAYS)
	{
		cast_singleray(ra, i, m);
		free(m->caster);
		i++;
		ra += FOV_ANGLE / NUM_RAYS;
		colum++;
	}
}

unsigned long	create_rgb(int r, int g, int b)
{
	return (((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff));
}

void	new_x_y(t_img *img, t_rend *m, int i)
{
	if (m->rays[i / 2].washitvertical)
		img->newx = (int)m->rays[i / 2].wallhity % WALL_SIZE;
	else
		img->newx = (int)m->rays[i / 2].wallhitx % WALL_SIZE;
}
