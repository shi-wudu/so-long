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

char    **copy_map(char **ber)
{
	int     i;
	int     height;
	char    **copy;

	height = 0;
	i = 0;
	while(ber[height])
		height++;
	copy = malloc(sizeof(char *) * (height + 1));
	if (!copy)
		return (NULL);
	while(i < height)
	{
		if (!(copy[i] = ft_strdup(ber[i])))
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
        return;

    if (map[y][x] == 'C' || map[y][x] == 'E')
        (*items)++;

    map[y][x] = '1'; 

    flood_fill(map, x + 1, y, items);  // Right
    flood_fill(map, x - 1, y, items);  // Left
    flood_fill(map, x, y + 1, items);  // Down
    flood_fill(map, x, y - 1, items);  // Up
}
int	is_it_valid(char **map, int collectibles)
{
	char	**cpy;
	int			x;
	int			y;
	int		items;
	int		object;

	if(!find_player(map, &x, &y))
		return(0);

	cpy = copy_map(map);
	if(!cpy)
		return (0);
	
	items = 0;
	flood_fill(cpy, x, y, &items);
	free_args(cpy);

	object = collectibles + 1;
	return (items == object);
}