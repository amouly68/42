/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 14:43:47 by amouly            #+#    #+#             */
/*   Updated: 2022/11/23 12:10:55 by amouly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	parse(const char c, va_list ptr)
{
	if (c == 'c')
		return (ft_putchar_fd(va_arg(ptr, int), 1));
	if (c == '%')
		return (write(1, "%", 1));
	if (c == 's')
		return (ft_putstr_fd(va_arg(ptr, char *), 1));
	if (c == 'p')
		return (ft_putpointer(va_arg(ptr, unsigned long long int)));
	if (c == 'd' || c == 'i')
		return (ft_putnbr_fd(va_arg(ptr, int), 1));
	if (c == 'u')
		return (ft_putnbr_u_fd(va_arg(ptr, int), 1));
	if (c == 'x')
		return (ft_putnbr_base(va_arg(ptr, int), "0123456789abcdef"));
	if (c == 'X')
		return (ft_putnbr_base(va_arg(ptr, int), "0123456789ABCDEF"));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		count;
	va_list	ptr;
	int		a;
	
	i = 0;
	a = 0;
	count = 0;
	va_start(ptr, str);
	while (str[i])
	{
		if (str[i] != '%')
		{
			if (ft_putchar_fd(str[i], 1) != -1)
				count++;
			else 
				return (-1);
		}
		else if (str[i] == '%')
		{
			a = parse(str[i + 1], ptr) ;
			if (a == -1)
				return (-1);
			count += a;
			i++;
		}
		i++;
	}
	return (count);
	va_end(ptr);
}
