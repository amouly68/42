/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 15:34:04 by amouly            #+#    #+#             */
/*   Updated: 2022/11/23 17:43:14 by amouly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_putstr_fd(const char *s, int fd);
int		ft_putchar_fd(char c, int fd);
int		parse(const char c, va_list ptr, int *count);
int		ft_printf(const char *str, ...);
int		ft_putnbr_fd(int n, int fd);
int		ft_putnbr_u_fd(unsigned int n, int fd);
int		ft_putnbr_base(unsigned int nbr, char *base);
int		ft_putpointer(unsigned long long int pointer);
int		ft_count_num(long int n);

#endif
