/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 17:16:17 by amouly            #+#    #+#             */
/*   Updated: 2022/11/04 12:35:41 by amouly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strnstr(const char *haystack, const char *needle, unsigned int len)
{
	unsigned int	a;
	unsigned int	b;
	char			*hay;

	a = 0;
	hay = (char *) haystack;
	if (needle[0] == '\0')
		return (hay);
	while (a < len && hay[a] != '\0')
	{
		if (hay[a] == needle[0] && needle[0] != '\0')
		{
			b = 0;
			while (hay[a + b] == needle[b] && needle[b] != '\0')
				b++;
			if (needle[b] == '\0' && (a + b <= len))
				return (&hay[a]);
		}
		a++;
	}
	return (NULL);
}
