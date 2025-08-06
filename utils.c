/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnakasto <mnakasto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 19:28:10 by mnakasto          #+#    #+#             */
/*   Updated: 2025/08/05 18:42:30 by mnakasto         ###   ########.fr       */
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

int	print_error(char *message, char **map)
{
	ft_printf("%s", message);
	if (map)
		free_map(map);
	exit(EXIT_FAILURE);
	return (0);
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

int	close_window(t_game *game)
{
	free_map(game->map);
	exit(0);
	return (0);
}
