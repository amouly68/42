/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 13:28:35 by amouly            #+#    #+#             */
/*   Updated: 2022/12/20 09:17:47 by amouly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <unistd.h>
#include "libft/libft.h"
#include <signal.h>

void	handler(int signal)
{
	static unsigned char	car = 255;

	if (signal == SIGUSR1)
		car = car << 1;
	else if (signal == SIGUSR2)
	{
		car = car << 1;
		car = car | 1;
	}
	if (car <= 128)
	{
		ft_putchar_fd(car, 1);
		car = 255;
	}
	usleep(150);
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
