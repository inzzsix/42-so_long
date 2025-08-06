/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnakasto <mnakasto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 11:51:59 by mnakasto          #+#    #+#             */
/*   Updated: 2025/04/04 11:06:11 by mnakasto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/get_next_line.h"
#include "../headers/libft.h"

static char	*extract_remaining(char *line)
{
	int		i;
	char	*left;

	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
		i++;
	if (line[i] == '\0' || line[i + 1] == '\0')
		return (NULL);
	left = ft_substr(line, i + 1, ft_strlen(line) - (i + 1));
	if (!left)
		return (NULL);
	return (left);
}

char	*extract_line(const char *line)
{
	int		i;
	char	*new_line;

	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
		i++;
	new_line = ft_substr(line, 0, i + 1);
	if (!new_line || *new_line == '\0')
		return (NULL);
	return (new_line);
}

static char	*ft_find_line(int fd, char *buffer, char *left)
{
	char	*temp;
	int		i;

	i = 20;
	while (i > 0)
	{
		i = read(fd, buffer, BUFFER_SIZE);
		if (i < 0)
		{
			free (left);
			return (NULL);
		}
		if (i == 0)
			break ;
		buffer[i] = '\0';
		if (!left)
			left = ft_strdup("");
		temp = left;
		left = ft_strjoin(temp, buffer);
		free (temp);
		temp = NULL;
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (left);
}

char	*get_next_line(int fd)
{
	static char	*left;
	char		*buffer;
	char		*line;
	char		*temp;

	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		free(buffer);
		free(left);
		buffer = NULL;
		left = NULL;
		return (NULL);
	}
	line = ft_find_line(fd, buffer, left);
	free(buffer);
	if (!line)
		return (NULL);
	temp = extract_line(line);
	left = extract_remaining(line);
	free (line);
	return (temp);
}
/*
int	main(void)
{
	int	fd;
	char *line;
	fd = open("get_next_line.h", O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break;
		printf("%s", line);
		free (line);
	}
}
*/
