/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marleand <marleand@student42.lisboa.pt>    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-07-29 19:16:03 by marleand          #+#    #+#             */
/*   Updated: 2025-07-29 19:16:03 by marleand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


static int	can_it_move(t_game *game, int new_x, int new_y)
{
    if (game->map[new_y][new_x] == '1')
        return (0);
    
    return (1);
}

static void	handle_w_key(t_game *game)
{
	if (can_it_move(game, game->player_x, game->player_y - 1))
	{
		if (game->map[game->player_y - 1][game->player_x] == 'C')
		{
			game->remaining_c--;
			game->map[game->player_y - 1][game->player_x] = '0';
		}
		game->player_y--;
		game->moves++;
		ft_printf("Moves: %d\n", game->moves);
        render_map(game);
        render_player(game);
		if (game->map[game->player_y][game->player_x] == 'E' && game->remaining_c == 0)
		{
			ft_printf("YOU WIN! Completed in %d moves!\n", game->moves);
			cleanup(game);
			exit(0);
		}
	}
}

static void	handle_s_key(t_game *game)
{
	if (can_it_move(game, game->player_x, game->player_y + 1))
	{
		if (game->map[game->player_y + 1][game->player_x] == 'C')
		{
			game->remaining_c--;
			game->map[game->player_y + 1][game->player_x] = '0';
		}
		game->player_y++;
		game->moves++;
        render_map(game);
        render_player(game);
		ft_printf("Moves: %d\n", game->moves);
		if (game->map[game->player_y][game->player_x] == 'E' && game->remaining_c == 0)
		{
			ft_printf("YOU WIN! Completed in %d moves!\n", game->moves);
			cleanup(game);
			exit(0);
		}
	}
}

static void	handle_a_key(t_game *game)
{
	if (can_it_move(game, game->player_x - 1, game->player_y))
	{
		if (game->map[game->player_y][game->player_x - 1] == 'C')
		{
			game->remaining_c--;
			game->map[game->player_y][game->player_x - 1] = '0';
		}
		game->player_x--;
		game->moves++;
        render_map(game);
        render_player(game);
		ft_printf("Moves: %d\n", game->moves);
		if (game->map[game->player_y][game->player_x] == 'E' && game->remaining_c == 0)
		{
			ft_printf("YOU WIN! Completed in %d moves!\n", game->moves);
			cleanup(game);
			exit(0);
		}
	}
}

static void	handle_d_key(t_game *game)
{
	if (can_it_move(game, game->player_x + 1, game->player_y))
	{
		if (game->map[game->player_y][game->player_x + 1] == 'C')
		{
			game->remaining_c--;
			game->map[game->player_y][game->player_x + 1] = '0';
		}
		game->player_x++;
		game->moves++;
        render_map(game);
        render_player(game);
		ft_printf("Moves: %d\n", game->moves);
		if (game->map[game->player_y][game->player_x] == 'E' && game->remaining_c == 0)
		{
			ft_printf("YOU WIN! Completed in %d moves!\n", game->moves);
			cleanup(game);
			exit(0);
		}
	}
}

int	key_handler(int keycode, t_game *game)
{
	if (keycode == ESC_KEY)
	{
		cleanup(game);
		exit(0);
	}
	if (keycode == W_KEY)
		handle_w_key(game);
	if (keycode == S_KEY)
		handle_s_key(game);
	if (keycode == A_KEY)
		handle_a_key(game);
	if (keycode == D_KEY)
		handle_d_key(game);
		
	return (0);
}