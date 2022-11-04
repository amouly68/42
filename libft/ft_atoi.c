/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 17:33:32 by amouly            #+#    #+#             */
/*   Updated: 2022/11/04 11:26:22 by amouly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_atoi(const char *str)
{
	int	i;
	int	neg;
	int	num;

	i = 0;
	num = 0;
	neg = 1;
	while (str[i] != '\0' && (str[i] == 32 || str[i] == '\t'
		|| str[i] == '\r' || str[i] == '\n'
		|| str[i] == '\v' || str[i] == '\f'))
		i++;
	if (str[i] != '\0' && (str[i] == '+' || str[i] == '-'))
	{
		if (str[i] == '-')
			neg = -1;
		i++;
	}
	while (str[i] != '\0' && (str[i] >= '0' && str[i] <= '9' ))
	{
		num = (num * 10) + (str[i] - 48);
		i++;
	}		
	num = num * neg;
	return (num);
}
