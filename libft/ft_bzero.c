/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 14:51:50 by amouly            #+#    #+#             */
/*   Updated: 2022/11/03 15:32:52 by amouly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	ft_bzero(void *s, unsigned int n)
{
	unsigned int	a;
	unsigned char	*temp;

	temp = s;
	a = 0;
	while (a < n)
	{
		temp[a] = (unsigned char) 0;
		a++;
	}
}
