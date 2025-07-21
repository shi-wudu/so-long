/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marleand <marleand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 13:29:32 by marleand          #+#    #+#             */
/*   Updated: 2025/01/14 13:29:32 by marleand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 8
# endif

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

int		newline(char *buffer);
char	*get_next_line(int fd);
char	*fstrjoin(char const *s1, char const *s2);
void	*ft_memmove(void *dest, const void *src, size_t n);

#endif