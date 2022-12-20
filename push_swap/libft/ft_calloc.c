/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 12:12:26 by amouly            #+#    #+#             */
/*   Updated: 2022/11/04 12:34:11 by amouly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_calloc(unsigned int count, unsigned int size)
{
	unsigned char	*debut;
	unsigned int	a;
	unsigned int	b;

	a = count * size * sizeof(unsigned char);
	b = 0;
	debut = malloc(a);
	if (debut == NULL)
		return (NULL);
	while (b < a)
	{
		debut[b] = (unsigned char) 0;
		b++;
	}
	return (debut);
}
