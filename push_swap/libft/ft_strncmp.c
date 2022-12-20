/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 13:12:34 by amouly            #+#    #+#             */
/*   Updated: 2022/11/03 13:29:29 by amouly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int	ft_strncmp(const char *s1, const char *s2, unsigned int n)
{
	unsigned int		i;
	const unsigned char	*us1;
	const unsigned char	*us2;

	us1 = (const unsigned char *) s1;
	us2 = (const unsigned char *) s2;
	i = 0;
	if (n == 0)
		return (0);
	while ((us1[i] != '\0') && (us2[i] != '\0')
		&& (us1[i] == us2[i]) && (i < n - 1))
	{
		i++;
	}
	if (us1[i] == us2[i])
		return (0);
	else
		return (us1[i] - us2[i]);
}
