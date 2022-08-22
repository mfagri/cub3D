/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_keys.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfagri <mfagri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 18:26:19 by mfagri            #+#    #+#             */
/*   Updated: 2022/07/30 15:22:29 by mfagri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	get_index(t_rend *m, int *x, int *y)
{
	*y = 0;
	while (m->map[*y])
	{
		*x = 0;
		while (m->map[*y][*x])
		{
			if (m->map[*y][*x] == m->player)
				return ;
			(*x)++;
		}
		(*y)++;
	}
}

void	player_rendering(t_rend *m)
{
	if (m->key_w)
		player_next_position(m, 1);
	if (m->key_s)
		player_next_position(m, 2);
	if (m->key_a)
		player_next_position(m, 3);
	if (m->key_d)
		player_next_position(m, 4);
	if (m->key_left)
		m->pplayer->rotatangle += m->pplayer->rotation_speed;
	if (m->key_right)
		m->pplayer->rotatangle -= m->pplayer->rotation_speed;
}

int	key_press(int key, t_rend *m)
{
	if (key == W)
		m->key_w = 1;
	if (key == S)
		m->key_s = 1;
	if (key == A)
		m->key_a = 1;
	if (key == D)
		m->key_d = 1;
	if (key == ARW_RIGHT)
		m->key_right = 1;
	if (key == ARW_LEFT)
		m->key_left = 1;
	if (key == ESC)
		exit(0);
	return (0);
}

int	key_release(int key, t_rend *m)
{
	if (key == W)
		m->key_w = 0;
	if (key == S)
		m->key_s = 0;
	if (key == A)
		m->key_a = 0;
	if (key == D)
		m->key_d = 0;
	if (key == ARW_RIGHT)
		m->key_right = 0;
	if (key == ARW_LEFT)
		m->key_left = 0;
	return (0);
}
