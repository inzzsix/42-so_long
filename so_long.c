/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnakasto <mnakasto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 16:32:38 by mnakasto          #+#    #+#             */
/*   Updated: 2025/04/03 19:55:06 by mnakasto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
<<<<<<< HEAD:so_long.c

int	check_extension(char *s);


char **read_map(char *file)
{
	int fd;
	char  *all_lines;
	char	*line;
	char	*temp;
	char	**map;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (printf("Error\nLe descripteur de fichier est invalide"), NULL);
	all_lines = ft_strdup("");
	if(!all_lines)
		return (NULL);
	while((line = get_next_line(fd)))
	{
		temp = ft_strjoin(all_lines, line);
		free(all_lines);
		all_lines = temp;
		free(line);
	}
	close (fd);
	map = ft_split(all_lines, '\n');
	free(all_lines);
	return (map);
}

int	main(int ac, char **av)
{
	if (ac != 2)
		return (1);
	if (!check_extension(av[1]))
		return (printf("Erreur\nLe nom de fichier est invalide") * 0);
	return(0);
}
=======
int	check_extension;

int	main(int ac, char **av)
{
	int fd;

	fd = open("av[1]", O_RDONLY);
	if (!fd)
		return (printf("Error\nLe descripteur de fichier est invalide") * 0);
	if (!check_extension)
		return (printf("Erreur\nLe nom de fichier est invalide") * 0);
	
}
>>>>>>> 523210be967e943887faa2e2113bfcdb1fa44047:so_long/so_long.c
