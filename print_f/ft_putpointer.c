/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 13:43:11 by amouly            #+#    #+#             */
/*   Updated: 2022/11/22 14:55:11 by amouly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_putnbr_long_base(unsigned long long int nbr, char *base)
{
	long long int	nb;
	long long int	nb1;
	int				ret;

	ret = 0;
	nb = nbr;
	nb1 = nb % 16;
	nb = nb / 16;
	if (nb != 0)
		ret += ft_putnbr_long_base(nb, base);
	ret += write(1, &base[nb1], 1);
	return (ret);
}

int	ft_putpointer(unsigned long long int pointer)
{
	int	ret;

	if (pointer == 0)
		ret = write(1, "0x0", 3);
	else
	{
		ret = write(1, "0x", 2);
		ret += ft_putnbr_long_base(pointer, "0123456789abcdef");
	}
	return (ret);
}
