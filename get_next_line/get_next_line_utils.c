/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 14:43:47 by amouly            #+#    #+#             */
/*   Updated: 2022/11/23 17:49:08 by amouly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	parse(const char c, va_list ptr, int *count)
{
	int	verif;

	verif = *count;
	if (c == 'c')
		*count += (ft_putchar_fd(va_arg(ptr, int), 1));
	if (c == '%')
		*count += (write(1, "%", 1));
	if (c == 's')
		*count += (ft_putstr_fd(va_arg(ptr, char *), 1));
	if (c == 'p')
		*count += (ft_putpointer(va_arg(ptr, unsigned long long int)));
	if (c == 'd' || c == 'i')
		*count += (ft_putnbr_fd(va_arg(ptr, int), 1));
	if (c == 'u')
		*count += (ft_putnbr_u_fd(va_arg(ptr, int), 1));
	if (c == 'x')
		*count += (ft_putnbr_base(va_arg(ptr, int), "0123456789abcdef"));
	if (c == 'X')
		*count += (ft_putnbr_base(va_arg(ptr, int), "0123456789ABCDEF"));
	if (*count < verif)
		return (-1);
	return (*count);
}

int	ft_printf(const char *str, ...)
{
	int		count;
	va_list	ptr;

	count = 0;
	va_start(ptr, str);
	while (*str)
	{
		if (*str != '%')
		{
			if (ft_putchar_fd(*str, 1) == -1)
				return (-1);
			count++;
		}
		else if (*str == '%')
		{
			str++;
			if (parse(*str, ptr, &count) == -1)
				return (-1);
		}
		str++;
	}
	return (count);
	va_end(ptr);
}
