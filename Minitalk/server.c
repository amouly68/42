/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 13:28:35 by amouly            #+#    #+#             */
/*   Updated: 2022/12/20 11:10:50 by amouly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <unistd.h>
#include "libft/libft.h"
#include <signal.h>

void	handler(int signal)
{
	static unsigned char	car = 255;
	static int				i = 0;

	if (signal == SIGUSR1)
		car = car << 1;
	else if (signal == SIGUSR2)
	{
		car = car << 1;
		car = car | 1;
	}
	i++;
	if (i == 8)
	{
		ft_putchar_fd(car, 1);
		car = 255;
		i = 0;
	}
}

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	ft_printf("Le pid est : %d\n", pid);
	signal(SIGUSR1, handler);
	signal(SIGUSR2, handler);
	while (1)
	{
		pause();
	}
}
