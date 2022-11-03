/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 14:51:50 by amouly            #+#    #+#             */
/*   Updated: 2022/11/03 15:20:09 by amouly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memset(void *b, int c, unsigned int len)
{
	unsigned int	a;
	unsigned char	*temp;

	temp = b;
	a = 0;
	while (a < len)
	{
		temp[a] = (unsigned char) c;
		a++;
	}
	return (b);
}
