/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marleand <marleand@student42.lisboa.pt>    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-07-21 10:45:41 by marleand          #+#    #+#             */
/*   Updated: 2025-07-21 10:45:41 by marleand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	is_wall_row(char *row)
{
	int	i;

	i = 0;
	while (row[i])
	{
		if (row[i] != '1')		// entire row must be walls
			return (0);
		i++;
	}
	return (1);
}

static int	parse_line(char *line, int *pce)
{
	int	i;

	if (line[0] != '1' || line[ft_strlen(line) - 1] != '1')		// sides must be walls
		return (0);
	i = 0;
	while (line[i])
	{
		if (line[i] == 'P')
			pce[0]++;
		else if (line[i] == 'C')
			pce[1]++;
		else if (line[i] == 'E')
			pce[2]++;
		else if (line[i] != '1' && line[i] != '0')		// invalid character
			return (0);
		i++;
	}
	return (1);
}

static int	final_parser(char **ber, int *pce)
{
	int	i;

	i = 0;
	while (ber[i])		// find last row
		i++;
	if (!is_wall_row(ber[0]) || !is_wall_row(ber[i - 1]))		// top/bottom borders
		return (0);
	if (pce[0] != 1 || pce[2] != 1 || pce[1] < 1)		// exactly 1P, 1E, at least 1C
		return (0);

	if (!is_it_valid(ber, pce[1]))
    	return (0);
	return (1);
}


int	parser(int fd, char **ber, int *amount_of_collectibles)
{
	char	*line;
	size_t		map_len;
	int		pce[3];		// P, C, E counters
	int		i;

	i = 0;
	map_len = 1;		// haven't set width yet
	ft_bzero(pce, sizeof(pce));
	line = get_next_line(fd);
	while (line)
	{
		if (map_len == 1)		// first line sets width standard
			map_len = ft_strlen(line);
		if (ft_strlen(line) != map_len || !parse_line(line, pce))
			return (print_error("Map line invalid."), free_args(ber), 0);
		ber[i++] = line;
		line = get_next_line(fd);
	}
	ber[i] = NULL;
	if (!final_parser(ber, pce))
		return (print_error("Map invalid."), free_args(ber), 0);

	*amount_of_collectibles = pce[1];
	return (1);
}
