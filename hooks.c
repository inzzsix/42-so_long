/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnakasto <mnakasto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 22:09:46 by mnakasto          #+#    #+#             */
/*   Updated: 2025/08/14 19:32:06 by mnakasto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

#define KEY_ESC 65307
#define KEY_W 119
#define KEY_A 97
#define KEY_S 115
#define KEY_D 100

int	handle_escape(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
		cleanup_and_exit(game, 0);
	return (0);
}

int	handle_movement(int keycode, t_game *game)
{
	int	moved;

	moved = 0;
	if (keycode == KEY_A)
	{
		move_player_left(game);
		moved = 1;
	}
	else if (keycode == KEY_D)
	{
		move_player_right(game);
		moved = 1;
	}
	else if (keycode == KEY_W)
	{
		move_player_up(game);
		moved = 1;
	}
	else if (keycode == KEY_S)
	{
		move_player_down(game);
		moved = 1;
	}
	return (moved);
}

int	key_hook(int keycode, t_game *game)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	handle_escape(keycode, game);
	if (handle_movement(keycode, game))
	{
		game->move_count++;
		draw_map(game, y, x);
		printf("count :\t%d\n", game->move_count);
	}
	return (0);
}

int	check_extension(char *s)
{
	size_t	len;

	len = strlen(s);
	if (len < 4)
		return (0);
	return (s[len - 1] == 'r' && s[len - 2] == 'e'
		&& s[len - 3] == 'b' && s[len - 4] == '.');
}
