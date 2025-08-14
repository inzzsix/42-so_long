/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnakasto <mnakasto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 16:32:38 by mnakasto          #+#    #+#             */
/*   Updated: 2025/08/14 20:59:38 by mnakasto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	initialize_game(t_game *game, int ac, char **av)
{
	game->move_count = 0;
	if (!parse_args(ac, av))
		return (0);
	if (!read_and_validate_map(game, av[1]))
		return (0);
	return (1);
}

int	main(int ac, char **av)
{
	t_game	game;
	t_mlx	mlx_struct;

	ft_bzero(&game, sizeof(t_game));
	ft_bzero(&mlx_struct, sizeof(t_mlx));
	if (ac == 2)
	{
		ft_bzero(&game, sizeof(t_game));
		game.mlx_data = &mlx_struct;
		if (!initialize_game(&game, ac, av))
			cleanup_and_exit(&game, 1);
		init_mlx(game.mlx_data, &game);
		launch_mlx(game.mlx_data, &game);
		cleanup_and_exit(&game, 0);
	}
	else
		ft_printf("Error\nInvalid number of args");
	return (0);
}
