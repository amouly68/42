/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 14:51:50 by amouly            #+#    #+#             */
/*   Updated: 2022/11/04 16:10:02 by amouly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memcpy(void *dest, const void *src, unsigned int n)
{
	unsigned int	a;
	unsigned char	*temp;
	unsigned char	*car;

	temp = (unsigned char *) dest;
	car = (unsigned char *) src;
	a = 0;
	if (dest != NULL || src != NULL)
	{
		while (a < n && n != 0)
		{
			temp[a] = car [a];
			a++;
		}
	}
	return (temp);
}
