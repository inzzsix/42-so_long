/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_and_validate_map.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnakasto <mnakasto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 16:24:42 by mnakasto          #+#    #+#             */
/*   Updated: 2025/08/14 17:07:58 by mnakasto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	read_map_loop(int fd, char **all_lines)
{
	char	*line;
	char	*temp;

	line = get_next_line(fd);
	while (line)
	{
		temp = ft_strjoin(*all_lines, line);
		free(*all_lines);
		free(line);
		if (!temp)
			return (print_error("Error\nAlloc fail\n", NULL));
		*all_lines = temp;
		line = get_next_line(fd);
	}
	return (1);
}

static int	read_map(t_game *game, char *file)
{
	int		fd;
	char	*all_lines;

	all_lines = ft_strdup("");
	if (!all_lines)
		return (print_error("Error\nAlloc fail\n", NULL));
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (free(all_lines),
			print_error("Error\nInvalid file descriptor\n", NULL));
	if (!read_map_loop(fd, &all_lines))
		return (close(fd), free(all_lines),
			print_error("Error\nAlloc fail\n", NULL));
	close(fd);
	game->map = ft_split(all_lines, '\n');
	free(all_lines);
	if (!game->map)
		return (print_error("Error\nFailed to allocate map\n", NULL));
	return (1);
}

static int	is_exit_reachable(char **m, int i, int j)
{
	int	h;
	int	w;

	h = 0;
	while (m[h])
		h++;
	if (!m[0])
		return (0);
	w = (int)ft_strlen(m[0]);
	if (i > 0 && m[i - 1][j] == 'V')
		return (1);
	if (i + 1 < h && m[i + 1][j] == 'V')
		return (1);
	if (j > 0 && m[i][j - 1] == 'V')
		return (1);
	if (j + 1 < w && m[i][j + 1] == 'V')
		return (1);
	return (0);
}

int	check_map_exit(char **m)
{
	int	i;
	int	j;

	i = 0;
	while (m[i])
	{
		j = 0;
		while (m[i][j])
		{
			if (m[i][j] == 'E' && !is_exit_reachable(m, i, j))
			{
				ft_printf("Error\nPlayer cannot reach the exit\n");
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	read_and_validate_map(t_game *game, char *filename)
{
	char	**map_copy;

	if (!read_map(game, filename))
		return (0);
	get_map_size(game);
	if (!check_rectangular(game))
		return (print_error("Error\nMap is not rectangular\n", game->map));
	if (!check_map_elements(game))
		return (print_error("Error\nInvalid map elements\n", game->map));
	if (!check_walls(game))
		return (print_error("Error\nMissing walls\n", game->map));
	map_copy = copy_map(game);
	if (!map_copy)
		return (print_error("Error\nMap copy failed\n", game->map));
	flood_fill(game, map_copy, game->player_x, game->player_y);
	if (!check_map_exit(map_copy))
		return (free_map(map_copy), 0);
	free_map(map_copy);
	return (1);
}
