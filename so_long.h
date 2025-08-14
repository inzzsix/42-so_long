/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnakasto <mnakasto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 14:49:24 by mnakasto          #+#    #+#             */
/*   Updated: 2025/08/14 20:13:06 by mnakasto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/headers/libft.h"
# include "libft/headers/get_next_line.h"
# include "libft/headers/ft_printf.h"
# include "mlx/mlx.h"
# include "mlx/mlx_int.h"

# define NB_TEX 5

typedef struct s_texture
{
	void	*img;
	int		w;
	int		h;
}	t_texture;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
}	t_mlx;

typedef struct s_game
{
	char		**map;
	int			height;
	int			width;
	int			p_count;
	int			c_count;
	int			e_count;
	int			player_x;
	int			player_y;
	int			exit_x;
	int			exit_y;
	int			prev_x;
	int			prev_y;
	char		*tex_paths[NB_TEX];
	void		*background;
	void		*wall;
	void		*player;
	void		*collec;
	void		*exit;
	int			move_count;
	t_mlx		*mlx_data;
	t_texture	tex[NB_TEX];
}	t_game;

void	find_player(t_game *game);
void	flood_fill(t_game *g, char **map, int x, int y);
char	**copy_map(t_game *game);
void	free_map(char **map);
void	move_player_left(t_game *game);
void	move_player_right(t_game *game);
void	move_player_up(t_game *game);
void	move_player_down(t_game *game);
void	init_mlx(t_mlx *mlx, t_game *game);
void	launch_mlx(t_mlx *mlx, t_game *game);
void	load_images(t_game *game);
void	draw_background_at(t_game *game, int x, int y);
void	draw_tile(t_game *game, int x, int y);
void	render_frame_move(t_game *game);
void	draw_background(t_game *game);	
void	draw_map_elements(t_game *game);

int		key_hook(int keycode, t_game *game);
int		close_window(t_game *game);
int		render_frame(t_game *game);
int		can_move_to(t_game *game, int new_x, int new_y);
int		print_error(char *message, char **map);
int		check_walls(t_game *game);
int		parse_args(int ac, char **av);
int		check_extension(char *s);
int		check_rectangular(t_game *game);
int		check_map_elements(t_game *game);
void	check_map_elements2(t_game *game, char letter, int i, int j);
int		read_and_validate_map(t_game *game, char *filename);
void	init_paths(t_game *game);
void	draw_map(t_game *g, int y, int x);
void	load_textures(t_game *game);
void	destroy_images(t_game *game);
void	destroy_mlx(t_game *game);
void	cleanup_and_exit(t_game *game, int status);
int		check_map_exit(char **m);
void	get_map_size(t_game *game);
int		in_bounds(t_game *g, int x, int y);
int		can_move_to(t_game *game, int new_x, int new_y);

#endif
