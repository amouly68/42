/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 13:46:33 by amouly            #+#    #+#             */
/*   Updated: 2022/11/05 14:29:43 by amouly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*sjoin;
	int		a;
	int		b;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	a = ft_strlen(s1);
	b = ft_strlen(s2);
	sjoin = malloc (sizeof(char) * (a + b +1));
	if (sjoin == NULL)
		return (NULL);
	ft_strlcpy(sjoin, s1, (a + 1));
	ft_strlcpy(sjoin + a, s2, (b + 1));
	return (sjoin);
}
