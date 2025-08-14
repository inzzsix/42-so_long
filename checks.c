/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnakasto <mnakasto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 20:37:48 by mnakasto          #+#    #+#             */
/*   Updated: 2025/08/10 12:33:34 by mnakasto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_rectangular(t_game *game)
{
	int		i;
	size_t	expected_len;

	i = 0;
	if (!game->map || !game->map[0])
		return (0);
	expected_len = strlen(game->map[0]);
	while (game->map[i])
	{
		if (strlen(game->map[i]) != expected_len)
			return (0);
		i++;
	}
	return (1);
}

int	check_tile(t_game *game, char tile, int i, int j)
{
	if (tile != '0' && tile != '1' && tile != 'P' && tile != 'E' && tile != 'C')
		return (0);
	if (tile == 'P')
		check_map_elements2(game, 'P', i, j);
	else if (tile == 'E')
		check_map_elements2(game, 'E', i, j);
	else if (tile == 'C')
		game->c_count++;
	return (1);
}

int	check_map_elements(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	game->p_count = 0;
	game->e_count = 0;
	game->c_count = 0;
	while (i < game->height)
	{
		j = 0;
		while (j < (int)ft_strlen(game->map[i]))
		{
			if (!check_tile(game, game->map[i][j], i, j))
				return (0);
			j++;
		}
		i++;
	}
	if (game->p_count != 1 || game->e_count != 1 || game->c_count < 1)
		return (0);
	return (1);
}

int	check_walls(t_game *game)
{
	int	i;
	int	j;

	j = 0;
	while (j < game->width)
	{
		if (game->map[0][j] != '1' || game->map[game->height - 1][j] != '1')
			return (0);
		j++;
	}
	i = 0;
	while (i < game->height)
	{
		if (game->map[i][0] != '1' || game->map[i][game->width - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

void	check_map_elements2(t_game *game, char letter, int i, int j)
{
	if (letter == 'P')
	{
		game->p_count++;
		game->player_x = j;
		game->player_y = i;
	}
	if (letter == 'E')
	{
		game->exit_x = j;
		game->exit_y = i;
		game->e_count++;
	}
}
