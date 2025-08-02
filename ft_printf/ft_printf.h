/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marleand <marleand@student42.lisboa.pt>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 16:39:47 by marleand          #+#    #+#             */
/*   Updated: 2025/08/02 17:13:52 by marleand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# include <limits.h>

int		ft_printf(const char *str, ...);
int		ft_hexa(int flag, unsigned long n, char *base);
int		ft_putunsign(unsigned int n);
int		ft_putstr(char *s);
int		ft_putchar(char c);
int		ft_putnbr(int n);

#endif