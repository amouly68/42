/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 12:54:06 by amouly            #+#    #+#             */
/*   Updated: 2022/11/23 12:40:12 by amouly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_fd(int n, int fd)
{
	int	nb1;
	int	b;
	int	ret;

	ret = 1;
	b = 0;
	if (n == -2147483648)
		n = ++b + n;
	if (n < 0)
	{
		n = -n;
		if (ft_putchar_fd('-', fd) == -1)
			return (-1);
		ret++ ;
	}
	nb1 = n % 10 + '0';
	n = n / 10;
	if (n != 0)
		ret += ft_putnbr_fd(n, fd);
	if (b == 1)
		nb1++;
	if (ft_putchar_fd(nb1, fd) == -1)
		return (-1);
	return (ret);
}
