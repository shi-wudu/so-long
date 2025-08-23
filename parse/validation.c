/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marleand <marleand@student42.lisboa.pt>    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-07-21 17:07:11 by marleand          #+#    #+#             */
/*   Updated: 2025-07-21 17:07:11 by marleand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

char	**copy_map(char **ber)
{
	int		i;
	int		height;
	char	**copy;

	height = 0;
	i = 0;
	while (ber[height])
		height++;
	copy = malloc(sizeof(char *) * (height + 1));
	if (!copy)
		return (NULL);
	while (i < height)
	{
		copy[i] = ft_strdup(ber[i]);
		if (!copy[i])
		{
			copy[i] = NULL;
			free_args(copy);
			return (NULL);
		}
		i++;
	}
	copy[i] = NULL;
	return (copy);
}

int	find_player(char **map, int *x, int *y)
{
	int	row;
	int	col;

	row = 0;
	while (map[row])
	{
		col = 0;
		while (map[row][col])
		{
			if (map[row][col] == 'P')
			{
				*x = col;
				*y = row;
				return (1);
			}
			col++;
		}
		row++;
	}
	return (0);
}

static void	flood_fill(char **map, int x, int y, int *items)
{
	if (!map[y] || !map[y][x] || map[y][x] == '1')
		return ;
	if (map[y][x] == 'C' || map[y][x] == 'E')
		(*items)++;
	map[y][x] = '1';
	flood_fill(map, x + 1, y, items);
	flood_fill(map, x - 1, y, items);
	flood_fill(map, x, y + 1, items);
	flood_fill(map, x, y - 1, items);
}

static int	but_is_it_valid(char **map)
{
	int	i;

	i = 0;
	if (!map || !map[0] || !map[0][0])
	{
		print_error("Empty or invalid map.");
		return (0);
	}
	while (map[i])
	{
		if (ft_strlen(map[i]) == 0)
		{
			print_error("Map contains empty lines");
			return (0);
		}
		i++;
	}
	return (1);
}

static int	check_valid_chars(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != '0' && map[i][j] != '1' &&
				map[i][j] != 'P' && map[i][j] != 'E' &&
				map[i][j] != 'C')
			{
				print_error("Invalid character in map");
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}
