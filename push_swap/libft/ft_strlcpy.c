/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 13:41:13 by amouly            #+#    #+#             */
/*   Updated: 2022/12/18 10:30:39 by amouly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

unsigned int	ft_strlcpy(char *dest, const char *src, unsigned int destsize)
{
	unsigned int	a;
	unsigned int	c;

	c = 0;
	a = 0;
	while (src[c] != '\0')
		c++;
	if (destsize == 0)
		return (c);
	while (a < destsize - 1 && src[a] != '\0')
	{
		dest[a] = src[a];
		a++;
	}
	dest[a] = '\0';
	return (c);
}
