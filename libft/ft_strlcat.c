/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 13:41:13 by amouly            #+#    #+#             */
/*   Updated: 2022/11/04 15:32:12 by amouly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

unsigned int	ft_strlcat(char *dest, const char *src, unsigned int destsize)
{
	unsigned int	i;
	unsigned int	a;
	unsigned int	b;

	i = 0;
	b = 0;
	a = 0;
	while (dest[i] != '\0')
		i++;
	while (src[b] != '\0')
		b++;
	if (destsize <= i)
		return (b + destsize);
	while (i < (destsize - 1) && src[a] != '\0')
	{
		dest[i] = src[a];
		i++;
		a++;
	}
	dest[i] = '\0';
	return (i + b - a);
}
