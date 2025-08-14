/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnakasto <mnakasto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 18:02:48 by mnakasto          #+#    #+#             */
/*   Updated: 2025/08/14 18:08:23 by mnakasto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	do_move(t_game *g, int nx, int ny)
{
	int	ox;
	int	oy;

	ox = g->player_x;
	oy = g->player_y;
	g->prev_x = ox;
	g->prev_y = oy;
	g->map[oy][ox] = '0';
	g->map[ny][nx] = 'P';
	g->player_x = nx;
	g->player_y = ny;
}

void	move_player_left(t_game *g)
{
	int	nx;
	int	ny;

	nx = g->player_x - 1;
	ny = g->player_y;
	if (can_move_to(g, nx, ny))
		do_move(g, nx, ny);
}

void	move_player_right(t_game *g)
{
	int	nx;
	int	ny;

	nx = g->player_x + 1;
	ny = g->player_y;
	if (can_move_to(g, nx, ny))
		do_move(g, nx, ny);
}

void	move_player_up(t_game *g)
{
	int	nx;
	int	ny;

	nx = g->player_x;
	ny = g->player_y - 1;
	if (can_move_to(g, nx, ny))
		do_move(g, nx, ny);
}

void	move_player_down(t_game *g)
{
	int	nx;
	int	ny;

	nx = g->player_x;
	ny = g->player_y + 1;
	if (can_move_to(g, nx, ny))
		do_move(g, nx, ny);
}
