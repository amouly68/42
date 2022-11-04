/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 12:39:14 by amouly            #+#    #+#             */
/*   Updated: 2022/11/04 12:54:18 by amouly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	char	*string;
	int		a;
	int		b;

	a = 0;
	b = 0;
	while (s1[a] != '\0')
		a++;
	string = malloc(sizeof(unsigned char) * (a + 1));
	if (string == NULL)
		return (NULL);
	while (b < a)
	{	
		string[b] = s1[b];
		b++;
	}
	string[b] = '\0';
	return (string);
}
