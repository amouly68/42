/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 10:24:52 by amouly            #+#    #+#             */
/*   Updated: 2022/11/06 11:12:09 by amouly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
/*int	ft_countnbr(int n)
{
	int	a;

	a = 0;
	while (n > 0)
	{
		n = n / 10;
		a++;
	}
	return (a);
}

char	*ft_itoa(int n)

{
	int		a;
	int		b;
	char	*nbr;

	b = ft_countnbr(n);
	nbr = malloc(sizeof(char) * (b + 1));
	if (nbr == NULL)
		return (NULL);
	a = 0;
	while (a < ft_countnbr(n))
	{
		nbr[b - 1] = (n % 10) + 48;
		n = n / 10;
		a++;
		b--;
	}
	nbr[ft_countnbr(n)] = '\0';
	return (nbr);
}*/

int main()
{
	char[3] = {0,1,2};
	int a = 0;
	int b = 1;
	int c = 2;
	int d = 3;

	char[0] = b + 48;
	char[1] = c + 48;
	char[2] = d + 48;

	while ( a < 3)
	{
		printf("%s\n", char[a]);
	}
}
