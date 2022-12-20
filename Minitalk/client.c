/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 13:28:53 by amouly            #+#    #+#             */
/*   Updated: 2022/12/20 09:16:44 by amouly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>

void	char_to_byte(unsigned char c, pid_t pid)
{
	int	i;
	int	j;

	if (c > 128 || pid < 0)
		return ;
	i = 0;
	j = 128;
	while (i < 8)
	{
		if ((c / j) % 2 == 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		j = j / 2;
		i++;
		usleep(150);
	}
}

int	main(int argc, char **argv)
{
	int	pid;
	int	i;	

	if (argc != 3)
		ft_printf("Nombre d'arguments invalide\n");
	pid = ft_atoi(argv[1]);
	i = 0;
	while (argv[2][i])
	{
		char_to_byte(argv[2][i], pid);
		usleep(150);
		i++;
	}
}
