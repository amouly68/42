/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 13:12:34 by amouly            #+#    #+#             */
/*   Updated: 2022/11/03 13:36:22 by amouly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strchr(const char *s, int c)
{
	int		a;
	char	b;
	char	*temp;

	b = (char) c;
	temp = (char *)s;
	a = 0;
	while ((temp[a] != b) && (temp[a] != '\0'))
		a++;
	if (temp[a] == b)
		return (&temp[a]);
	else
		return (NULL);
}
