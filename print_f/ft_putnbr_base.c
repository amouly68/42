/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 13:43:11 by amouly            #+#    #+#             */
/*   Updated: 2022/11/17 13:26:32 by amouly           ###   ########.fr       */
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

char	*ft_putnbr_base(int nbr, char *base)
{
	int				a;
	unsigned int	nb;	
	unsigned int	nb1;

	count = 0;
	a = ft_strlen(base);
	if (nbr < 0)
	{
			nb = -nbr;
			write (1, "-", 1);
	}
	else
		nb = nbr;
	nb1 = nb % a;
	nb = nb / a;
	if (nb != 0)
		ft_putnbr_base(nb, base);
	write (1, &base[nb1], 1);
}


int ft_putnbr_hexa_min(int nbr)
{
	int count;
	char *base;
	char *str;

	base[] = "0123456789ABCDEF"
	
	


}


