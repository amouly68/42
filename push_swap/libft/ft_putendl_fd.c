/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 12:54:06 by amouly            #+#    #+#             */
/*   Updated: 2022/11/05 13:35:09 by amouly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

void	ft_putendl_fd(char *s, int fd)
{
	int	a;

	a = 0;
	if ((fd < 0 || fd > 255) || s == NULL)
		return ;
	while (s[a] != '\0')
	{
		write(fd, &s[a], 1);
		a++;
	}
	write(fd, "\n", 1);
}
