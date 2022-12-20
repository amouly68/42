/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd_printf.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 12:54:06 by amouly            #+#    #+#             */
/*   Updated: 2022/12/18 10:44:28 by amouly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_fd_printf(int n, int fd)
{
	int	nb1;
	int	b;
	int	ret;

	ret = ft_count_num(n);
	b = 0;
	if (n == -2147483648)
		n = ++b + n;
	if (n < 0)
	{
		n = -n;
		if (ft_putchar_fd_printf('-', fd) == -1)
			return (-1);
	}
	nb1 = n % 10 + '0';
	if (n / 10 != 0)
	{
		if (ft_putnbr_fd_printf(n / 10, fd) == -1)
			return (-1);
	}
	if (b == 1)
		nb1++;
	if (ft_putchar_fd_printf(nb1, fd) == -1)
		return (-1);
	return (ret);
}
