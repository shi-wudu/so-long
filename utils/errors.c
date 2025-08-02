/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marleand <marleand@student42.lisboa.pt>    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-07-21 14:32:12 by marleand          #+#    #+#             */
/*   Updated: 2025-07-21 14:32:12 by marleand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_args(char **args)
{
	char	**temp;

	temp = args;
	if (!args)
		return ;
	while (*temp)
	{
		free(*temp);
		temp++;
	}
	free(args);
}

void	cleanup(t_game *game)
{
	if(game->win)
		mlx_destroy_window(game->mlx, game->win);

	if(game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	if(game->map)
		free_args(game->map);
}

void	print_error(char *msg)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(msg, 2);
	ft_putstr_fd("\n", 2);
}

int	is_it_ber(char *map)
{
	int	len;

	if (!map)
		return (0);
	len = ft_strlen(map);
	if (len < 4)
		return (0);
	if (map[len - 4] == '.' &&
		map[len - 3] == 'b' &&
		map[len - 2] == 'e' &&
		map[len - 1] == 'r')
		return (1);
	return (0);
}

int	close_handler(t_game *game)
{
	cleanup(game);
	exit(0);
}
