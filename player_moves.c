/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnakasto <mnakasto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 22:27:28 by mnakasto          #+#    #+#             */
/*   Updated: 2025/08/04 19:22:30 by mnakasto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	can_move_to(t_game *game, int new_x, int new_y)
{
	int	target;
	int	i;

	i = 0;
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
		if (game->c_count > i)
			return (0);
		else
			exit (EXIT_SUCCESS);
	}
	return (1);
}

void	move_player_left(t_game *game)
{
	int	old_x;
	int	old_y;
	int	new_x;
	int	new_y;

	if (!can_move_to(game, game->player_x - 1, game->player_y))
		return ;
	old_x = game->player_x;
	old_y = game->player_y;
	new_x = old_x - 1;
	new_y = old_y;
	if (new_x < 0)
		return ;
	if (!can_move_to(game, new_x, new_y))
		return ;
	game->prev_x = old_x;
	game->prev_y = old_y;
	game->map[old_y][old_x] = '0';
	game->map[new_y][new_x] = 'P';
	game->player_x = new_x;
}

void	move_player_right(t_game *game)
{
	int	old_x;
	int	old_y;
	int	new_x;
	int	new_y;

	if (!can_move_to(game, game->player_x + 1, game->player_y))
		return ;
	old_x = game->player_x;
	old_y = game->player_y;
	new_x = old_x + 1;
	new_y = old_y;
	if (new_x > game->width)
		return ;
	if (!can_move_to(game, new_x, new_y))
		return ;
	game->prev_x = old_x;
	game->prev_y = old_y;
	if (game->map[game->player_y][new_x] != '1')
	{
		game->map[old_y][old_x] = '0';
		game->map[new_y][new_x] = 'P';
		game->player_x = new_x;
	}
}

void	move_player_up(t_game *game)
{
	int	old_x;
	int	old_y;
	int	new_x;
	int	new_y;

	if (!can_move_to(game, game->player_x, game->player_y - 1))
		return ;
	old_x = game->player_x;
	old_y = game->player_y;
	new_x = old_x;
	new_y = old_y - 1;
	if (new_y < 0)
		return ;
	if (!can_move_to(game, new_x, new_y))
		return ;
	game->prev_x = old_x;
	game->prev_y = old_y;
	if (game->map[game->player_y][new_x] != '1')
	{
		game->map[old_y][old_x] = '0';
		game->map[new_y][new_x] = 'P';
		game->player_y = new_y;
	}
}

void	move_player_down(t_game *game)
{
	int	old_x;
	int	old_y;
	int	new_x;
	int	new_y;

	if (!can_move_to(game, game->player_x, game->player_y + 1))
		return ;
	old_x = game->player_x;
	old_y = game->player_y;
	new_x = old_x;
	new_y = old_y + 1;
	if (new_y > game->height)
		return ;
	if (!can_move_to(game, new_x, new_y))
		return ;
	game->prev_x = old_x;
	game->prev_y = old_y;
	if (game->map[game->player_y][new_x] != '1')
	{
		game->map[old_y][old_x] = '0';
		game->map[new_y][new_x] = 'P';
		game->player_y = new_y;
	}
}
