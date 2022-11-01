/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 13:12:34 by amouly            #+#    #+#             */
/*   Updated: 2022/11/01 13:56:07 by amouly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*strrchr(const char *s, int c)
{
	int		a;
	char	*temp;

	a = 0;
	temp = (char *)s;
	while (s[a])
		a++;
	while ((temp[a] != c) && (a >= 0))
		a--;
	if (temp[a] == c)
		return (&temp[a]);
	else
		return (NULL);
}
