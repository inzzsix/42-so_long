/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnakasto <mnakasto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 21:27:05 by mnakasto          #+#    #+#             */
/*   Updated: 2025/08/14 18:13:45 by mnakasto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	in_bounds(t_game *g, int x, int y)
{
	return (x >= 0 && x < g->width && y >= 0 && y < g->height);
}

int	can_move_to(t_game *game, int new_x, int new_y)
{
	int	target;

	if (!in_bounds(game, new_x, new_y))
		return (0);
	target = game->map[new_y][new_x];
	if (target == '1')
		return (0);
	if (target == 'C')
	{
		game->c_count--;
		game->map[new_y][new_x] = '0';
	}
	if (target == 'E')
	{
		if (game->c_count > 0)
			return (0);
		cleanup_and_exit(game, EXIT_SUCCESS);
	}
	return (1);
}

void	find_player(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->height)
	{
		j = 0;
		while (j < game->width)
		{
			if (game->map[i][j] == 'P')
			{
				game->player_x = j;
				game->player_y = i;
				return ;
			}
			j++;
		}
		i++;
	}
}

void	flood_fill(t_game *g, char **map, int x, int y)
{
	if (x < 0 || x >= g->width || y < 0 || y >= g->height)
		return ;
	if (map[y][x] == '1' || map[y][x] == 'V' || map[y][x] == 'E')
		return ;
	map[y][x] = 'V';
	flood_fill(g, map, x - 1, y);
	flood_fill(g, map, x + 1, y);
	flood_fill(g, map, x, y - 1);
	flood_fill(g, map, x, y + 1);
}
