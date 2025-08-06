/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnakasto <mnakasto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 22:09:46 by mnakasto          #+#    #+#             */
/*   Updated: 2025/08/06 19:41:05 by mnakasto         ###   ########.fr       */
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
	{
		free_map(game->map);
		exit(0);
	}
	return (0);
}

int	handle_movement(int keycode, t_game *game)
{
	if (keycode == KEY_A)
		move_player_left(game);
	else if (keycode == KEY_D)
		move_player_right(game);
	else if (keycode == KEY_W)
		move_player_up(game);
	else if (keycode == KEY_S)
		move_player_down(game);
	else
		return (0);
	game->move_count++;
	return (1);
}

int	key_hook(int keycode, t_game *game)
{
	int	y;
	int	x;

	x = 0;
	y = 0;
	handle_escape(keycode, game);
	if (!handle_movement(keycode, game))
		return (0);
	draw_map(game, y, x);
	printf("count :\t%d\n", game->move_count);
	return (0);
}

int	check_extension(char *s)
{
	int	i;

	i = 0;
	if (strlen(s) < 4)
		return (0);
	while (s[i] != '\0')
		i++;
	if (s[i - 1] == 'r' && s[i - 2] == 'e'
		&& s[i - 3] == 'b' && s[i - 4] == '.')
		return (1);
	return (0);
}
