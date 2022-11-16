/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 14:43:47 by amouly            #+#    #+#             */
/*   Updated: 2022/11/16 17:40:54 by amouly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libftprintf.h"

void	parse(const char *str, va_list ptr)
{
	if (str[0] == '%' && str[1] == 's')
		ft_putstr_fd(va_arg(ptr, char *), 1);
	if (str[0] == '%' && str[1] == 'd')
		ft_putnbr_fd(va_arg(ptr, int), 1);
	
}



int ft_printf(const char *str, ...)
{
	int i;
	va_list ptr;

	i = 0;
	va_start(ptr, str);
	while (str[i])
	{
		if (str[i] != '%')
			ft_putchar_fd(str[i], 1);
		if (str[i] == '%')
		{
			parse(&str[i], ptr);
			i++;
		}
		i++;
	}
	return (0);
}


int main()
{
	//printf("idajs\n%d\nkbdjkasb\n%s", 45, "TEST");
	ft_printf("idajs\n%d\nkbdjkasb\n%s", 45, "TEST");
}
