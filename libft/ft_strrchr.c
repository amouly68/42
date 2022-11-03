/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 13:12:34 by amouly            #+#    #+#             */
/*   Updated: 2022/11/03 13:38:02 by amouly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strrchr(const char *s, int c)
{
	int		a;
	char	b;
	char	*temp;

	b = (char) c;
	a = 0;
	temp = (char *)s;
	while (s[a] != '\0')
		a++;
	while ((temp[a] != b) && (a > 0))
		a--;
	if (temp[a] == b)
		return (&temp[a]);
	else
		return (NULL);
}
