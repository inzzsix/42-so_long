/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnakasto <mnakasto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 19:28:10 by mnakasto          #+#    #+#             */
/*   Updated: 2025/08/14 20:38:18 by mnakasto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**copy_map(t_game *game)
{
	char	**map_cpy;
	int		i;

	i = 0;
	map_cpy = malloc(sizeof(char *) * (game->height + 1));
	if (!map_cpy)
		exit(EXIT_FAILURE);
	while (i < game->height)
	{
		map_cpy[i] = ft_strdup(game->map[i]);
		i++;
	}
	map_cpy[i] = NULL;
	return (map_cpy);
}

void	free_map(char **map)
{
	int	i;

	i = 0;
	if (!map)
		return ;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

int	print_error(char *message, char **map)
{
	ft_printf("%s", message);
	if (map)
		free_map(map);
	return (0);
}

void	destroy_images(t_game *game)
{
	if (!game || !game->mlx_data || !game->mlx_data->mlx)
		return ;
	if (game->background)
		mlx_destroy_image(game->mlx_data->mlx, game->background);
	if (game->wall)
		mlx_destroy_image(game->mlx_data->mlx, game->wall);
	if (game->player)
		mlx_destroy_image(game->mlx_data->mlx, game->player);
	if (game->collec)
		mlx_destroy_image(game->mlx_data->mlx, game->collec);
	if (game->exit)
		mlx_destroy_image(game->mlx_data->mlx, game->exit);
	game->background = NULL;
	game->wall = NULL;
	game->player = NULL;
	game->collec = NULL;
	game->exit = NULL;
}

void	destroy_mlx(t_game *game)
{
	if (!game || !game->mlx_data)
		return ;
	if (game->mlx_data->mlx)
	{
		if (game->mlx_data->win)
		{
			mlx_destroy_window(game->mlx_data->mlx, game->mlx_data->win);
			game->mlx_data->win = NULL;
		}
		mlx_destroy_display(game->mlx_data->mlx);
		free(game->mlx_data->mlx);
		game->mlx_data->mlx = NULL;
	}
}
