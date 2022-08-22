/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfagri <mfagri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 21:45:47 by mfagri            #+#    #+#             */
/*   Updated: 2022/07/30 14:56:55 by mfagri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	init_colors(char *s, char **element, int i, t_rend *game)
{
	char	**t;

	if (element[i][0] == 'F')
	{
		s = ft_strrchr(element[i], ' ');
		t = ft_split(s, ',');
		game->colors->f[0] = atoi(t[0]);
		game->colors->f[1] = atoi(t[1]);
		game->colors->f[2] = atoi(t[2]);
		ft_free(NULL, t);
	}
	else
	{
		s = ft_strrchr(element[i], ' ');
		t = ft_split(s, ',');
		game->colors->c[0] = atoi(t[0]);
		game->colors->c[1] = atoi(t[1]);
		game->colors->c[2] = atoi(t[2]);
		ft_free(NULL, t);
	}
}

void	init_textters(char *s, char **element, int i, t_rend *game)
{
	if (element[i][0] == 'N' && element[i][1] == 'O')
	{
		s = ft_strrchr(element[i], ' ');
		s++;
		game->textter->no = strdup(s);
	}
	else if (element[i][0] == 'S' && element[i][1] == 'O')
	{
		s = ft_strrchr(element[i], ' ');
		s++;
		game->textter->so = strdup(s);
	}
	else if (element[i][0] == 'W' && element[i][1] == 'E')
	{
		s = ft_strrchr(element[i], ' ');
		s++;
		game->textter->we = strdup(s);
	}
	else if (element[i][0] == 'E' && element[i][1] == 'A')
	{
		s = ft_strrchr(element[i], ' ');
		s++;
		game->textter->ea = strdup(s);
	}
}
