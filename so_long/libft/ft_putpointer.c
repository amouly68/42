/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 13:43:11 by amouly            #+#    #+#             */
/*   Updated: 2022/11/23 16:33:53 by amouly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_putnbr_long_base(unsigned long long int nbr, char *base)
{
	unsigned long long int	nb;
	unsigned long long int	nb1;
	int						ret;
	int						a;

	ret = 1;
	a = 0;
	nb = nbr;
	nb1 = nb % 16;
	nb = nb / 16;
	if (nb != 0)
	{
		a = ft_putnbr_long_base(nb, base);
		if (a == -1)
			return (-1);
		ret += a;
	}
	if (write(1, &base[nb1], 1) == -1)
		return (-1);
	return (ret);
}

int	ft_putpointer(unsigned long long int pointer)
{
	int	ret;
	int	a;

	a = 0;
	if (pointer == 0)
	{
		ret = write(1, "0x0", 3);
		if (ret == -1)
			return (-1);
	}
	else
	{
		ret = write(1, "0x", 2);
		if (ret == -1)
			return (-1);
		a = ft_putnbr_long_base(pointer, "0123456789abcdef");
		if (a == -1)
			return (-1);
		ret += a;
	}
	return (ret);
}
