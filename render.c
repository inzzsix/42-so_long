/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnakasto <mnakasto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 14:59:39 by mnakasto          #+#    #+#             */
/*   Updated: 2025/08/06 12:57:05 by mnakasto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_background_at(t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->mlx_data->mlx,
		game->mlx_data->win,
		game->tex[0].img, x * 64, y * 64);
}

void	init_paths(t_game *game)
{
	game->tex_paths[0] = "textures/background.xpm";
	game->tex_paths[1] = "textures/wall.xpm";
	game->tex_paths[2] = "textures/collectible.xpm";
	game->tex_paths[3] = "textures/player.xpm";
	game->tex_paths[4] = "textures/exit.xpm";
}

void	load_textures(t_game *game)
{
	int	width;
	int	height;

	width = 0;
	height = 0;
	game->background = mlx_xpm_file_to_image(game->mlx_data->mlx,
			"textures/background.xpm", &width, &height);
	game->wall = mlx_xpm_file_to_image(game->mlx_data->mlx,
			"textures/wall.xpm", &width, &height);
	game->player = mlx_xpm_file_to_image(game->mlx_data->mlx,
			"textures/player.xpm", &width, &height);
	game->collec = mlx_xpm_file_to_image(game->mlx_data->mlx,
			"textures/collectible.xpm", &width, &height);
	game->exit = mlx_xpm_file_to_image(game->mlx_data->mlx,
			"textures/exit.xpm", &width, &height);
	if (!game->background || !game->wall || !game->player || !game->collec
		|| !game->exit)
	{
		ft_printf("Error:\nxpm file is not available\n");
		mlx_destroy_window(game->mlx_data->mlx, game->mlx_data->win);
		mlx_destroy_display(game->mlx_data->mlx);
		exit(EXIT_FAILURE);
	}
}

void	draw_map(t_game *g, int y, int x)
{
	y = 0;
	while (y < g->height)
	{
		x = 0;
		while (x < g->width)
		{
			mlx_put_image_to_window(g->mlx_data->mlx, g->mlx_data->win,
				g->background, x * 64, y * 64);
			if (g->map[y][x] == '1')
				mlx_put_image_to_window(g->mlx_data->mlx,
					g->mlx_data->win, g->wall, x * 64, y * 64);
			if (g->map[y][x] == 'P')
				mlx_put_image_to_window(g->mlx_data->mlx,
					g->mlx_data->win, g->player, x * 64, y * 64);
			if (g->map[y][x] == 'E')
				mlx_put_image_to_window(g->mlx_data->mlx, g->mlx_data->win,
					g->exit, x * 64, y * 64);
			if (g->map[y][x] == 'C')
				mlx_put_image_to_window(g->mlx_data->mlx, g->mlx_data->win,
					g->collec, x * 64, y * 64);
			x++;
		}
		y++;
	}
}
