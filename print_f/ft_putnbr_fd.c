/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 12:54:06 by amouly            #+#    #+#             */
/*   Updated: 2022/11/17 14:32:53 by amouly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

int count_nbr(int nbr)
{
	int count;

	count = 0;
	if (nbr == 0)
		return 1;
	if (nbr < 0)
	{
		count ++;
		nbr = -nbr;
	}
	while (nbr != 0)
	{
		nbr = nbr / 10;
		count ++;
	}
	return (count);
}

int	ft_putnbr(int n)
{
	char *ret;
	int a;

	a = 0;
	ret = malloc(sizeof(char) * (count_nbr(n) + 1));
	if (ret == NULL)
		return (-1);
	if (n < 0)
	{
		ret[0] = '-';
		a++;
	}
	while (a < count_nbr())
		return ;
	if (n == -2147483648)
		n = ++b + n;
	if (n < 0)
	{
		n = -n;
		write(fd, "-", 1);
	}
	nb1 = n % 10 + '0';
	n = n / 10;
	if (n != 0)
		ft_putnbr_fd(n, fd);
	if (b == 1)
		nb1++;
	write (fd, &nb1, 1);
}

int	ft_putnbr(int n)
{
	ft_putnbr_fd(n, 1);
	return(count_nbr(n));
}


