/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd_printf.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 12:54:06 by amouly            #+#    #+#             */
/*   Updated: 2022/12/18 10:41:29 by amouly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstr_fd_printf(const char *s, int fd)
{
	int	a;

	a = 0;
	if (fd < 0 || fd > 255)
		return (-1);
	if (s == NULL)
		return (ft_putstr_fd_printf("(null)", 1));
	while (s[a] != '\0')
	{
		if (write(fd, &s[a], 1) == -1)
			return (-1);
		a++;
	}
	return (a);
}
