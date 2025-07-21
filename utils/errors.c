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

#include "so_long"

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

void	print_error(char *msg)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(msg, 2);
	ft_putstr_fd("\n", 2);
}
