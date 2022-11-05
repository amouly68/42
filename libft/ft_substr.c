/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 13:46:33 by amouly            #+#    #+#             */
/*   Updated: 2022/11/05 14:27:16 by amouly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char				*sjoin;

	if (s == NULL)
		return (NULL);
	sjoin = malloc (sizeof(char) * (len + 1));
	if (sjoin == NULL)
		return (NULL);
	ft_strlcpy(sjoin, &s[start], (len + 1));
	sjoin[len + 1] = '\0';
	return (sjoin);
}
