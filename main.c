/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marleand <marleand@student42.lisboa.pt>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 11:26:00 by marleand          #+#    #+#             */
/*   Updated: 2025/07/29 20:28:34 by marleand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <fcntl.h>

int main(int argc, char **argv)
{
	int		fd;
	char	**map;
	int collectible_count;
	t_game game;

	if (argc != 2)
		return (print_error("Usage: ./so_long <map.ber>"), 1);

	if (!is_it_ber(argv[1]))
		return (print_error("Map file must have .ber extension"), 1);
	
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (print_error("Cannot open file"), 1);
	
	map = malloc(sizeof(char *) * 101);
	if (!map)
		return (close(fd), print_error("Memory allocation failed"), 1);
	
	if (!parser(fd, map, &collectible_count))
	    return (close(fd), free_args(map), 1);
	
	init_game(&game, map, collectible_count);
	mlx_key_hook(game.win, key_handler, &game);
	mlx_loop(game.mlx);
	
	return (0);
}