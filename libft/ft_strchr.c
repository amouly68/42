/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 13:12:34 by amouly            #+#    #+#             */
/*   Updated: 2022/11/01 13:49:45 by amouly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*strchr(const char *s, int c)
{
	int		a;
	char	*temp;

	temp = (char *)s;
	a = 0;
	while ((temp[a] != c) && (temp[a] != '\0'))
		a++;
	if (temp[a] == c)
		return (&temp[a]);
	else
		return (NULL);
}
