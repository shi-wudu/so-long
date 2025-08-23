/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marleand <marleand@student42.lisboa.pt>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 11:26:00 by marleand          #+#    #+#             */
/*   Updated: 2025/08/23 10:29:22 by marleand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <fcntl.h>

int	main(int argc, char **argv)
{
	int		fd;
	char	**map;
	int		collectible_count;
	t_game	game;

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
	ft_memset(map, 0, sizeof(char *) * 101);
	if (!parser(fd, map, &collectible_count))
		return (close(fd), 1);
	if (!init_game(&game, map, collectible_count))
		return (free_args(map), 1);
	mlx_loop(game.mlx);
	free_args(map);
	return (0);
}
