/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 13:46:33 by amouly            #+#    #+#             */
/*   Updated: 2022/11/07 09:01:39 by amouly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, unsigned int len)
{
	char	*sub;
	int		leng;

	if (s == NULL)
		return (NULL);
	if (start >= (unsigned int)ft_strlen(s))
	{	
		sub = malloc(sizeof(char));
		if (sub == NULL)
			return (NULL);
		sub[0] = '\0';
		return (sub);
	}
	if ((unsigned int)ft_strlen(s + start) < len)
		leng = ft_strlen(s + start);
	else
		leng = len;
	sub = malloc (sizeof(char) * (leng + 1));
	if (sub == NULL)
		return (NULL);
	ft_strlcpy(sub, &s[start], leng + 1);
	sub[leng] = '\0';
	return (sub);
}
