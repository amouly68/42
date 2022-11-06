/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 14:33:49 by amouly            #+#    #+#             */
/*   Updated: 2022/11/06 10:24:23 by amouly           ###   ########.fr       */
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
	int	a;
	int	b;

	a = 0;
	if (s1 == NULL)
		return (NULL);
	b = ft_strlen(s1)
	while ( isset(s1[b - 1, set] && s1[b - 1] != '\0')
			b--;
	if (s1[b - 1] == )

	if (isset(s1[a], set) && s1[a] != \0') 
			a++;
	
	}

}
