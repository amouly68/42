/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_u_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 12:54:06 by amouly            #+#    #+#             */
/*   Updated: 2022/11/23 16:17:23 by amouly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_u_fd(unsigned int n, int fd)
{
	int	nb1;
	int	ret;

	ret = ft_count_num(n);
	nb1 = n % 10 + '0';
	n = n / 10;
	if (n != 0)
	{
		if (ft_putnbr_fd(n, fd) == -1)
			return (-1);
	}
	if (ft_putchar_fd(nb1, fd) == -1)
		return (-1);
	return (ret);
}
