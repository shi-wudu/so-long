/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marleand <marleand@student42.lisboa.pt>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 11:23:19 by marleand          #+#    #+#             */
/*   Updated: 2025/07/21 11:52:34 by marleand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include "mlx_linux/mlx.h"
# include <stdbool.h>
# include <limits.h>
# include "stdio.h"

typedef struct s_data {
    void    *img;              // The MLX image pointer (used internally)
    char    *addr;             // Address of the image buffer (raw pixel data)
    int     bits_per_pixel;    // Bits per pixel (usually 32 for RGBA) (0, 0, 0, 0)
    int     line_length;       // Number of bytes in a single row of pixels
    int     endian;            // Not sure
}   t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
char	*get_next_line(int fd)

#endif