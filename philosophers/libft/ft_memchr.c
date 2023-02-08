/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 14:51:50 by amouly            #+#    #+#             */
/*   Updated: 2022/11/03 16:55:54 by amouly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memchr(const void *b, int c, unsigned int n)
{
	unsigned int	a;
	unsigned char	*temp;
	unsigned char	car;

	car = (unsigned char) c;
	temp = (unsigned char *) b;
	a = 0;
	while (a < n)
	{
		if (temp[a] == car)
			return (&temp[a]);
		a++;
	}
	return (NULL);
}
