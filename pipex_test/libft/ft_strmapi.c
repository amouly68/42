/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 10:09:17 by amouly            #+#    #+#             */
/*   Updated: 2022/11/07 10:21:48 by amouly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f) (unsigned int, char))
{
	char	*ret;
	int		i;

	i = 0;
	if (s == NULL)
		return (NULL);
	ret = malloc(sizeof (char) * (ft_strlen(s) + 1));
	if (ret == NULL)
		return (NULL);
	while (i < ft_strlen(s))
	{
		ret[i] = (*f)(i, s[i]);
		i++;
	}
	ret[i] = '\0';
	return (ret);
}
