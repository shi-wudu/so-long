/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marleand <marleand@student42.lisboa.pt>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 11:23:19 by marleand          #+#    #+#             */
/*   Updated: 2025/08/28 17:11:20 by marleand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdbool.h>
# include <limits.h>
# include <stdio.h>
# include "mlx_linux/mlx.h"
# include "Libft/libft.h"
# include "ft_printf/ft_printf.h"

# define TILE_SIZE 32
# define ESC_KEY 65307
# define W_KEY 119
# define A_KEY 97
# define S_KEY 115
# define D_KEY 100
# define MAX_WIDTH 1920
# define MAX_HEIGHT 1080

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	char	**map;
	int		player_x;
	int		player_y;
	int		moves;
	int		remaining_c;
	t_data	wall;
	t_data	floor;
	t_data	player;
	t_data	collectible;
	t_data	exit;
}	t_game;

int		parser(int fd, char **ber, int *collectible_count);
int		init_game(t_game *game, char **map, int collectible_count);
char	**copy_map(char **ber);
int		find_player(char **map, int *x, int *y);
int		is_it_ber(char *map);
int		is_it_valid(char **map, int collectibles);
void	free_args(char **args);
void	print_error(char *msg);
char	*get_next_line(int fd);
void	cleanup(t_game *game);
int		key_handler(int keycode, t_game *game);
int		ft_printf(const char *format, ...);
int		close_handler(t_game *game);
void	render_map(t_game *game);
void	render_player(t_game *game);
int		can_it_move(t_game *game, int new_x, int new_y);
int		check_valid_chars(char **map);
int		but_is_it_valid(char **map);
void	flood_fill(char **map, int x, int y, int *items);

#endif