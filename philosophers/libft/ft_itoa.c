/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 10:24:52 by amouly            #+#    #+#             */
/*   Updated: 2022/11/07 08:52:14 by amouly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_countnbr(int n)

{
	int	a;

	a = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n = -n;
		a++;
	}
	while (n > 0)
	{
		n = n / 10;
		a++;
	}
	return (a);
}

int	ifneg(int n)

{
	if (n < 0)
		return (-n);
	else
		return (n);
}

char	*ft_itoa(int n)

{
	int		a;
	int		b;
	int		n1;
	char	*nbr;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	b = ft_countnbr(n);
	n1 = ifneg(n);
	nbr = malloc(sizeof(char) * (b + 1));
	if (nbr == NULL)
		return (NULL);
	a = 0;
	while (a < ft_countnbr(n))
	{
		nbr[b - 1] = (n1 % 10) + 48;
		n1 = n1 / 10;
		a++;
		b--;
	}
	if (n < 0)
		nbr[0] = '-';
	nbr[ft_countnbr(n)] = '\0';
	return (nbr);
}
