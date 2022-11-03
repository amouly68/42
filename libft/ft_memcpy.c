/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 14:51:50 by amouly            #+#    #+#             */
/*   Updated: 2022/11/03 16:07:15 by amouly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memcpy(void *dest, const void *src, unsigned int n)
{
	unsigned int	a;
	unsigned char	*temp;

	temp = dest;
	a = 0;
	while (a < n)
	{
		temp[a] = (unsigned char) *src[a];
		a++;
	}
	return (dest);
}
