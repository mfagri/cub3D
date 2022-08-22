/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_position.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfagri <mfagri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 22:53:21 by mfagri            #+#    #+#             */
/*   Updated: 2022/08/03 17:24:02 by mfagri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	horizontal_wall_hit(t_rend *m)
{
	while (!is_end_window(m, m->caster->x_chk, m->caster->y_chk))
	{
		if (is_wall(m, m->caster->x_chk, m->caster->y_chk, '1'))
		{
			m->caster->hhitx = m->caster->x_chk;
			m->caster->hhity = m->caster->y_chk;
			m->caster->findhorzwall_hit = TRUE;
			break ;
		}
		else
		{
			m->caster->x_chk += m->caster->xstep;
			m->caster->y_chk += m->caster->ystep;
		}
	}
}

void	vertical_wall_hit(t_rend *m)
{
	while (!is_end_window(m, m->caster->vx_chk, m->caster->vy_chk))
	{
		if (is_wall(m, m->caster->vx_chk, m->caster->vy_chk, '1'))
		{
			m->caster->vhitx = m->caster->vx_chk;
			m->caster->vhity = m->caster->vy_chk;
			m->caster->findvir_wall = TRUE;
			break ;
		}
		else
		{
			m->caster->vx_chk += m->caster->xstep;
			m->caster->vy_chk += m->caster->ystep;
		}
	}
}

void	horizontal_ray(t_rend *m, float rayangel)
{
	m->caster->yintercept = floor(m->pplayer->y / WALL_SIZE) * WALL_SIZE;
	if (m->caster->rayisdown)
		m->caster->yintercept += WALL_SIZE;
	m->caster->xintercept = m->pplayer->x + \
		(m->caster->yintercept - m->pplayer->y) / tan(rayangel);
	m->caster->ystep = WALL_SIZE;
	if (m->caster->rayisup)
		m->caster->ystep *= -1;
	m->caster->xstep = WALL_SIZE / tan(rayangel);
	if (m->caster->rayisleft && m->caster->xstep > 0)
		m->caster->xstep *= -1;
	if (m->caster->rayisright && m->caster->xstep < 0)
		m->caster->xstep *= -1;
	m->caster->x_chk = m->caster->xintercept;
	m->caster->y_chk = m->caster->yintercept;
	if (m->caster->rayisup)
		m->caster->y_chk--;
	horizontal_wall_hit(m);
}

void	vertical_ray(t_rend *m, float rayangel)
{
	m->caster->findvir_wall = FALSE;
	m->caster->xintercept = floor(m->pplayer->x / WALL_SIZE) * WALL_SIZE;
	if (m->caster->rayisright)
		m->caster->xintercept += WALL_SIZE;
	m->caster->yintercept = m->pplayer->y + \
	(m->caster->xintercept - m->pplayer->x) * tan(rayangel);
	m->caster->xstep = WALL_SIZE;
	if (m->caster->rayisleft)
		m->caster->xstep *= -1;
	m->caster->ystep = WALL_SIZE * tan(rayangel);
	if (m->caster->rayisup && m->caster->ystep > 0)
		m->caster->ystep *= -1;
	if (m->caster->rayisdown && m->caster->ystep < 0)
		m->caster->ystep *= -1;
	m->caster->vx_chk = m->caster->xintercept;
	m->caster->vy_chk = m->caster->yintercept;
	if (m->caster->rayisleft)
			m->caster->vx_chk--;
	vertical_wall_hit(m);
}
