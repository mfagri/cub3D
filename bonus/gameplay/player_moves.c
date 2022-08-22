/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfagri <mfagri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 19:08:37 by mfagri            #+#    #+#             */
/*   Updated: 2022/08/15 19:08:40 by mfagri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	move_up(t_rend *m, int x, int y)
{
	x = round(m->pplayer->x + cos(m->pplayer->rotatangle) * 5);
	y = round(m->pplayer->y + sin(m->pplayer->rotatangle) * 5);
	if (m->map[(int)floor (y / WALL_SIZE)]
		[(int)floor (x / WALL_SIZE)] != '1'
		&& m->map[(int)floor((y) / WALL_SIZE)]
		[(int)floor((x + 4) / WALL_SIZE)] != '1'
		&& m->map[(int)floor((y) / WALL_SIZE)]
		[(int)floor((x - 4) / WALL_SIZE)] != '1'
		&& m->map[(int)floor((y - 4) / WALL_SIZE)]
		[(int)floor((x) / WALL_SIZE)] != '1'
		&& m->map[(int)floor((y + 4) / WALL_SIZE)]
		[(int)floor((x) / WALL_SIZE)] != '1')
	{
		m->pplayer->x = x;
		m->pplayer->y = y;
	}
}

void	move_down(t_rend *m, int x, int y)
{
	x = round(m->pplayer->x + cos(m->pplayer->rotatangle) * -3);
	y = round(m->pplayer->y + sin(m->pplayer->rotatangle) * -3);
	if (m->map[(int)floor (y / WALL_SIZE)]
		[(int)floor (x / WALL_SIZE)] != '1'
		&& m->map[(int)floor((y + 4) / WALL_SIZE)]
		[(int)floor((x + 4) / WALL_SIZE)] != '1'
		&& m->map[(int)floor((y - 4) / WALL_SIZE)]
		[(int)floor((x - 4) / WALL_SIZE)] != '1')
	{
		m->pplayer->x = x;
		m->pplayer->y = y;
	}
}

void	move_left(t_rend *m, int x, int y)
{
	x = round(m->pplayer->x + sin(m->pplayer->rotatangle) * 3);
	y = round(m->pplayer->y - cos(m->pplayer->rotatangle) * 3);
	if (m->map[(int)floor (y / WALL_SIZE)]
		[(int)floor (x / WALL_SIZE)] != '1'
		&& m->map[(int)floor((y + 4) / WALL_SIZE)]
		[(int)floor((x + 4) / WALL_SIZE)] != '1'
		&& m->map[(int)floor((y - 4) / WALL_SIZE)]
		[(int)floor((x - 4) / WALL_SIZE)] != '1')
	{
		m->pplayer->x = x;
		m->pplayer->y = y;
	}
}

void	move_right(t_rend *m, int x, int y)
{
	x = round(m->pplayer->x - sin(m->pplayer->rotatangle) * 3);
	y = round(m->pplayer->y + cos(m->pplayer->rotatangle) * 3);
	if (m->map[(int)floor (y / WALL_SIZE)]
		[(int)floor (x / WALL_SIZE)] != '1'
		&& m->map[(int)floor((y + 4) / WALL_SIZE)]
		[(int)floor((x + 4) / WALL_SIZE)] != '1'
		&& m->map[(int)floor((y - 4) / WALL_SIZE)]
		[(int)floor((x - 4) / WALL_SIZE)] != '1')
	{
		m->pplayer->x = x;
		m->pplayer->y = y;
	}
}

void	player_next_position(t_rend *m, int i)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	if (i == 1)
		move_up(m, x, y);
	if (i == 2)
		move_down(m, x, y);
	if (i == 3)
		move_left(m, x, y);
	if (i == 4)
		move_right(m, x, y);
}
