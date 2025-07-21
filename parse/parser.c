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

int	parse_the_map(int fd, char **ber)
{
    char	*line;
    int		map_len;
    int		pce[3];
    int		i;

    i = 0;
    map_len = -1;
    ft_bzero(pce, sizeof(pce));
    line = get_next_line(fd);
    while (line)
    {
        if (map_len == -1)
            map_len = ft_strlen(line);
        if ((int)ft_strlen(line) != map_len || !parse_line(line, pce))
            return (print_error("Map line invalid."), free_args(ber), 0);
        ber[i++] = line;
        line = get_next_line(fd);
    }
    ber[i] = NULL;
    if (!final_parser(ber, pce))
        return (print_error("Map invalid."), free_args(ber), 0);
    return (1);
}

int	parse_line(char *line, int *pce)
{
    int	i;

    if (line[0] != '1' || line[ft_strlen(line) - 1] != '1')
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
        else if (line[i] != '1' && line[i] != '0')
            return (0);
        i++;
    }
    return (1);
}

int	final_parser(char **ber, int *pce)
{
    int	i;
    int	j;

    i = 0;
    while (ber[i])
        i++;
    if (!is_wall_row(ber[0]) || !is_wall_row(ber[i - 1]))
        return (0);
    if (pce[0] != 1 || pce[2] != 1 || pce[1] < 1)
        return (0);
    return (1);
}

int	is_wall_row(char *row)
{
    int	i;

    i = 0;
    while (row[i])
    {
        if (row[i] != '1')
            return (0);
        i++;
    }
    return (1);
}
