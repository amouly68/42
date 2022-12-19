/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 13:28:53 by amouly            #+#    #+#             */
/*   Updated: 2022/12/19 18:13:53 by amouly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>

/*void char_to_byte(const unsigned char c, pid_t pid)
{
	unsigned char car;
	unsigned char modulo;
	int	i;
	
	car = c;
	i = 1;
	while (car > 0)
	{
		modulo = car % 2;
		if (modulo == 0)
		{
			kill(pid, SIGUSR1);
			ft_printf("0");
		}
		else if (modulo == 1)
		{
			kill(pid, SIGUSR2);
			ft_printf("1");
		}
		car = car / 2;
		i++;
		usleep(150);
	}
	while (i < 9)
	{
		kill(pid, SIGUSR1);
		ft_printf("0\n --NOUVELLE LETTRE -- \n");
		i++;
		usleep(150);
	}
}*/

void	char_to_byte(unsigned char c, pid_t pid)
{
	int	i = 0;
	int j = 128;
	while (i < 8)
	{
		if ((c / j) % 2 == 0)
		{
			ft_printf("0");
			kill(pid, SIGUSR1);
		}
		else 
		{
			ft_printf("1");
			kill(pid, SIGUSR2);
		}
		j = j / 2;
		i++;
		usleep(150);
	}
}




int main(int argc, char **argv)
{
	int pid;
	int	i;	
	
	pid = ft_atoi(argv[1]);
	i = 0;
	if (argc != 3)
		ft_printf("Nombre d'arguments invalide\n");
	while (argv[2][i])
	{
		char_to_byte(argv[2][i], pid);
		usleep(150);
		i++;
	}
}
