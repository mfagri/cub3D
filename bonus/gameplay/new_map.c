/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfagri <mfagri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 23:44:02 by mfagri            #+#    #+#             */
/*   Updated: 2022/07/30 14:58:29 by mfagri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	lines(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

int	longest_line_in_map(char **map)
{
	int	i;
	int	k;

	i = 6;
	k = ft_strlen(map[i]);
	while (map[i])
	{
		if (k < (int)ft_strlen(map[i]))
			k = ft_strlen(map[i]);
		i++;
	}
	return (k);
}

void	fill_eol_with_one(t_rend *game, char **map)
{
	while (game->mapx > game->j)
	{
		map[game->i][game->j] = '1';
		game->j++;
	}
}

void	final_map_2(t_rend *game, char **map, int *b, char **t_map)
{
	game->i = 5;
	while (map[++game->i])
	{
		game->j = -1;
		t_map[*b] = malloc(sizeof(char) * game->mapx + 1);
		if (!t_map[*b])
			ft_allocation_err();
		while (map[game->i][++game->j])
		{
			t_map[*b][game->j] = map[game->i][game->j];
			if (t_map[*b][game->j] == ' ')
				t_map[*b][game->j] = '1';
		}
		if (game->mapx > game->j)
		{
			while (game->mapx > game->j)
			{
				t_map[*b][game->j] = '1';
				game->j++;
			}
		}
		t_map[*b][game->j] = '\0';
		*b += 1;
	}
}

char	**final_map(t_rend *game, char **map)
{
	char	**t_map;
	int		b;

	game->mapx = longest_line_in_map(map);
	b = 0;
	t_map = malloc(sizeof(char *) * lines(map) - 6);
	if (!t_map)
		ft_allocation_err();
	final_map_2(game, map, &b, t_map);
	t_map[b] = NULL;
	ft_free(NULL, map);
	return (t_map);
}
