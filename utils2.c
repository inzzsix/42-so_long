/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnakasto <mnakasto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 17:08:08 by mnakasto          #+#    #+#             */
/*   Updated: 2025/08/14 20:07:20 by mnakasto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_map_size(t_game *game)
{
	int	i;

	i = 0;
	while (game->map[i])
		i++;
	game->height = i;
	if (game->map[0])
		game->width = (int)ft_strlen(game->map[0]);
	else
		game->width = 0;
}

int	parse_args(int ac, char **av)
{
	if (ac != 2)
	{
		ft_printf("Error\nUsage: %s <map.ber>\n", av[0]);
		return (0);
	}
	if (!check_extension(av[1]))
	{
		ft_printf("Error\nInvalid file extension. Expected .ber\n");
		return (0);
	}
	return (1);
}

void	cleanup_and_exit(t_game *game, int status)
{
	if (game)
	{
		destroy_images(game);
		destroy_mlx(game);
		free_map(game->map);
		game->map = NULL;
	}
	exit(status);
}

int	close_window(t_game *game)
{
	cleanup_and_exit(game, 0);
	return (0);
}
