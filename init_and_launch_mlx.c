/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_and_launch_mlx.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnakasto <mnakasto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 19:44:25 by mnakasto          #+#    #+#             */
/*   Updated: 2025/08/04 20:41:29 by mnakasto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_mlx(t_mlx *mlx, t_game *game)
{
	int	x_len;
	int	y_len;

	mlx->mlx = mlx_init();
	if (!mlx->mlx)
	{
		print_error("Error\nMLX initialization failed\n", game->map);
		exit(EXIT_FAILURE);
	}
	x_len = game->width * 64;
	y_len = game->height * 64;
	mlx->win = mlx_new_window(mlx->mlx, x_len, y_len, "So_long");
	if (!mlx->win)
	{
		print_error("Error\nWindow creation failed\n", game->map);
		exit(EXIT_FAILURE);
	}
}

void	launch_mlx(t_mlx *mlx, t_game *game)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	init_paths(game);
	load_textures(game);
	draw_map(game, y, x);
	mlx_hook(mlx->win, 17, 0, close_window, game);
	mlx_key_hook(mlx->win, key_hook, game);
	mlx_loop(mlx->mlx);
}
