/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_and_validate_map.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnakasto <mnakasto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 22:21:21 by mnakasto          #+#    #+#             */
/*   Updated: 2025/08/05 18:45:24 by mnakasto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	read_map(t_game *game, char *file)
{
	int		fd;
	char	*all_lines;
	char	*line;
	char	*temp;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (print_error("Error\nInvalid file descriptor\n", NULL));
	all_lines = ft_strdup("");
	line = get_next_line(fd);
	while (line != NULL)
	{
		temp = ft_strjoin(all_lines, line);
		free(all_lines);
		all_lines = temp;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	game->map = ft_split(all_lines, '\n');
	free(all_lines);
	if (!game->map)
		return (print_error("Error\nFailed to allocate map\n", NULL));
	return (1);
}

static void	get_map_size(t_game *game)
{
	int	i;

	i = 0;
	while (game->map[i])
		i++;
	game->height = i;
	if (game->map[0])
		game->width = ft_strlen(game->map[0]);
}

int	read_and_validate_map(t_game *game, char *filename)
{
	char	**map_copy;

	if (!read_map(game, filename))
		return (0);
	get_map_size(game);
	map_copy = copy_map(game);
	if (!map_copy)
		printf("map copy failed");
	if (!check_rectangular(game))
		return (print_error("Error\nMap is not rectangular\n", game->map));
	if (!check_map_elements(game))
		return (print_error("Error\nInvalid map elements\n", game->map));
	if (!check_walls(game))
		return (print_error("Error\nMissing walls\n", game->map));
	flood_fill(game, map_copy, game->player_x, game->player_y);
	check_map_exit(map_copy);
	free_map(map_copy);
	return (1);
}

void	flood_fill(t_game *g, char **map, int x, int y)
{
	if (x < 0 || x >= g->width || y < 0 || y >= g->height
		|| ft_strchr("1VE", map[y][x]))
		return ;
	map[y][x] = 'V';
	flood_fill(g, map, x - 1, y);
	flood_fill(g, map, x + 1, y);
	flood_fill(g, map, x, y - 1);
	flood_fill(g, map, x, y + 1);
}

void	check_map_exit(char **map_copy)
{
	int	i;
	int	j;

	i = 0;
	while (map_copy[i])
	{
		j = 0;
		while (map_copy[i][j])
		{
			if (map_copy[i][j] == 'E')
			{
				if (map_copy[i + 1][j] != 'V' && map_copy[i - 1][j] != 'V'
					&& map_copy[i][j + 1] != 'V' && map_copy[i][j - 1] != 'V')
				{
					printf("error: player cannot reach the exit\n");
					exit (1);
				}
			}
			j++;
		}
		i++;
	}
}
