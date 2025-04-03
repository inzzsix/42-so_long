/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnakasto <mnakasto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 21:27:05 by mnakasto          #+#    #+#             */
/*   Updated: 2025/04/03 21:50:06 by mnakasto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// find players position

void	find_player(char **map)
{
	int	i;
	int	j;
	int	player_x;
	int	player_y;

	i = 0;
	j = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
			{
				player_x = i;
				player_y = j;
				return ;
			}
		j++;
		}
		i++;
	}
}
