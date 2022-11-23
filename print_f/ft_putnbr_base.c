/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 13:43:11 by amouly            #+#    #+#             */
/*   Updated: 2022/11/23 16:13:28 by amouly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_strlen(char *str)
{
	int	a;

	a = 0;
	while (str[a] != '\0')
		a++;
	return (a);
}

int	ft_putnbr_base(unsigned int nbr, char *base)
{
	int				a;
	unsigned int	nb;	
	unsigned int	nb1;
	int				ret;

	ret = 1;
	a = 0;
	nb = nbr;
	nb1 = nb % ft_strlen(base);
	nb = nb / ft_strlen(base);
	if (nb != 0)
	{	
		a = ft_putnbr_base(nb, base);
		if (a == -1)
			return (-1);
		ret += a;
	}
	if (write(1, &base[nb1], 1) == -1)
		return (-1);
	return (ret);
}
