/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 13:13:34 by amouly            #+#    #+#             */
/*   Updated: 2022/11/04 17:27:25 by amouly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, unsigned int len)
{
	unsigned char	*tdest;
	unsigned char	*tsrc;

	tdest = (unsigned char *) dest;
	tsrc = (unsigned char *) src;
	if (dest != NULL || src != NULL)
	{
		if (src < dest)
		{
			while (len-- > 0)
				tdest[len] = tsrc[len];
		}
		else
		{	
			ft_memcpy(dest, src, len);
		}
	}
	return (tdest);
}
