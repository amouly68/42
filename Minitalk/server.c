/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 13:28:35 by amouly            #+#    #+#             */
/*   Updated: 2022/12/19 13:01:39 by amouly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <unistd.h>
#include "libft/libft.h"

int main()
{
	pid_t pid;
	pid = getpid();
	ft_printf("Le pid est : %d\n", pid);
	while (1)
	{
		signal(SIGSUR1, handler);
		signal(SIGSUR2, handler);
		pause();
	}
}
