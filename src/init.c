/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marleand <marleand@student42.lisboa.pt>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-07-28 17:20:24 by marleand          #+#    #+#             */
/*   Updated: 2025-08-02 17:20:24 by marleand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	init_window(t_game *game, int map_width, int map_height)
{
    game->mlx = mlx_init();
    if (!game->mlx)
        return (0);
    game->win = mlx_new_window(game->mlx, map_width * TILE_SIZE, 
            map_height * TILE_SIZE, "so_long");
    mlx_key_hook(game->win, key_handler, game);
    mlx_hook(game->win, 17, 0, close_handler, game);
    if (!game->win)
        return (0);
    return (1);
}

static int	load_textures(t_game *game)
{
    int	img_width;
    int	img_height;

    game->wall.img = mlx_xpm_file_to_image(game->mlx, "sprite/wall.xpm", 
            &img_width, &img_height);
    game->floor.img = mlx_xpm_file_to_image(game->mlx, "sprite/floor.xpm", 
            &img_width, &img_height);
    game->player.img = mlx_xpm_file_to_image(game->mlx, "sprite/player.xpm", 
            &img_width, &img_height);
    game->collectible.img = mlx_xpm_file_to_image(game->mlx, 
            "sprite/collectible.xpm", &img_width, &img_height);
    game->exit.img = mlx_xpm_file_to_image(game->mlx, "sprite/exit.xpm", 
            &img_width, &img_height);
    if (!game->wall.img || !game->floor.img || !game->player.img 
        || !game->collectible.img || !game->exit.img)
    {
        print_error("Failed to load textures");
        return (0);
    }
    return (1);
}

int	init_game(t_game *game, char **map, int collectible_count)
{
    int	map_width;
    int	map_height;

    map_height = 0;
    while (map[map_height])
        map_height++;
    map_width = ft_strlen(map[0]);
    if (!init_window(game, map_width, map_height))
        return (0);
    game->map = map;
    find_player(map, &game->player_x, &game->player_y);
    game->moves = 0;
    game->remaining_c = collectible_count;
    if (!load_textures(game))
        return (0);
    render_map(game);
    render_player(game);
    return (1);
}
