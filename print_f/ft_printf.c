/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 14:43:47 by amouly            #+#    #+#             */
/*   Updated: 2022/11/17 14:33:05 by amouly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	parse(const char *str, va_list ptr)
{
	if (str[0] == '%' && str[1] == 'c')
		return (ft_putchar_fd(va_arg(ptr, int), 1));
	if (str[0] == '%' && str[1] == '%')
		return (write(1,"%",1));
	if (str[0] == '%' && str[1] == 's')
		return (ft_putstr_fd(va_arg(ptr, char *), 1));
	if (str[0] == '%' && str[1] == 'd')
		return (ft_putnbr(va_arg(ptr, int));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		count;
	va_list	ptr;

	i = 0;
	count = 0;
	va_start(ptr, str);
	while (str[i])
	{
		if (str[i] != '%')
			count += ft_putchar_fd(str[i], 1);
		if (str[i] == '%')
		{
			count += parse(&str[i], ptr);
			i++;
		}
		i++;
	}
	return (count);
	va_end(ptr);
}
