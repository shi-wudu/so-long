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
find player ()

flood qlqr coisa

num sei