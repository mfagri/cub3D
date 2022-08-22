/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_extension.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfagri <mfagri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 19:06:58 by mfagri            #+#    #+#             */
/*   Updated: 2022/08/15 19:07:01 by mfagri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	check_extension(char *av)
{
	size_t	i;

	i = ft_strlen(av);
	if (av[i - 1] == 'b' && av[i - 2] == 'u' \
		&& av[i - 3] == 'c' && av[i - 4] == '.')
		return ;
	else
	{
		write (2, "Error\nWrong Extension!\n", 23);
		exit (1);
	}
}
