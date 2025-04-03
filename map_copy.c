/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_copy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnakasto <mnakasto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 20:52:06 by mnakasto          #+#    #+#             */
/*   Updated: 2025/04/03 21:26:15 by mnakasto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char **copy_map(char **original)
{
	char	**copy;
	int		height;
	int		i;
	
	copy = NULL;
	height = 0;
	i = 0;
	while (original[height])
		height++;
	copy = malloc(sizeof(char *) * (height + 1));
	if (!copy)
		return (NULL);
	while (i < height)
	{
		copy[i] = ft_strdup(original[i]);
		if(!copy[i])
			return (NULL);
		i++;;
	}
	copy[i] = NULL;
	return (copy);
}
