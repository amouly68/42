/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 14:51:50 by amouly            #+#    #+#             */
/*   Updated: 2022/11/03 17:12:16 by amouly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int	ft_memcmp(const void *s1, const void *s2, unsigned int n)
{
	unsigned int	a;
	unsigned char	*ts1;
	unsigned char	*ts2;

	ts1 = (unsigned char *) s1;
	ts2 = (unsigned char *) s2;
	a = 0;
	while (a < n)
	{
		if (ts1[a] != ts2[a])
			return (ts1[a] - ts2[a]);
		a++;
	}
	return (0);
}
