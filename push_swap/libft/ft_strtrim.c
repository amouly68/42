/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 14:33:49 by amouly            #+#    #+#             */
/*   Updated: 2022/11/07 09:44:01 by amouly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	isset(char const c, char const *set)
{
	int	a;

	a = 0;
	if (set == NULL)
		return (0);
	while (set[a] != '\0')
	{
		if (set[a] == c)
			return (1);
		a++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		a;
	int		b;

	a = 0;
	if (s1 == NULL)
		return (NULL);
	while (s1[a] != '\0' && isset(s1[a], set))
		a++;
	if (s1[a] == '\0')
		return (ft_strdup(""));
	b = ft_strlen(s1) - 1;
	while (b > a && isset(s1[b], set))
		b--;
	return (ft_substr(s1, a, b - a + 1));
}
