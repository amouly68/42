/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 12:54:06 by amouly            #+#    #+#             */
/*   Updated: 2022/11/23 12:04:01 by amouly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

int	ft_putstr_fd(const char *s, int fd)
{
	int	a;

	a = 0;
	if (fd < 0 || fd > 255)
		return (-1);
	if (s == NULL)
		return (ft_putstr_fd("(null)", 1));
	while (s[a] != '\0')
	{
		if (write(fd, &s[a], 1) == -1)
			return (-1);	
		a++;
	}
	return (a);
}
