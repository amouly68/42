/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 13:28:35 by amouly            #+#    #+#             */
/*   Updated: 2022/12/19 18:26:10 by amouly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <unistd.h>
#include "libft/libft.h"
#include <signal.h>

/*void	handler(int signal)
{
	static unsigned char	car = 0;
	
	if ((int)car > 128)
	{
		car = car << 1;
		ft_putchar_fd(car, 1);
		car = 0;
	}	
	while ((int)car <= 128)
	{
		if (signal == SIGUSR1)
			car = car >> 1;
		else if (signal == SIGUSR2)
		{
			car = car | 128;	
			car = car >> 1;
		}
	}
	if car
}
*/

void	handler(int signal)
{
	static	unsigned char car = 255;
	/*static	int i = 0;

	if (signal == SIGUSR2)
	{
		car = (car << 1) + 1;
	}
	else
	{
		car <<= 1;
	}
	if (i == 7)
	{
		write(1, &car, 1);
		car = 0;
		i = -1;
	}
	i++;*/
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




int main()
{
	pid_t 	pid;

	pid = getpid();
	//int i = 0;
	ft_printf("Le pid est : %d\n", pid);
	signal(SIGUSR1, handler);
	signal(SIGUSR2, handler);
	while (1)
	{
	//		pause();
		/*while (i < 8)
		{
			signal(SIGUSR1, handler);
			signal(SIGUSR2, handler);
			pause();
			i++;
		}
		i = 0;
		ft_printf("\n --- Nouvelle Lettre --- \n");*/
	}
}
