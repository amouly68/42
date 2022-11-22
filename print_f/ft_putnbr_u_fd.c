/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_u_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 12:54:06 by amouly            #+#    #+#             */
/*   Updated: 2022/11/22 12:57:44 by amouly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_u_fd(unsigned int n, int fd)
{
	int	nb1;
	int ret;

	ret = 0;
	if (fd < 0 || fd > 255)
		return (-1);
	nb1 = n % 10 + '0';
	n = n / 10;
	if (n != 0)
		ret += ft_putnbr_fd(n, fd);
	ret += ft_putchar_fd(nb1, fd);
	return (ret);
}
