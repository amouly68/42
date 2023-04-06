/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouly <amouly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 16:59:05 by amouly            #+#    #+#             */
/*   Updated: 2023/02/18 14:23:23 by amouly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_philo_total	philo;

	if ((ac != 5 && ac != 6) || av == NULL)
	{
		printf("nombre d'argument invalide\n");
		return (-1);
	}
	if (!(parse_philo(&philo, av, ac)))
	{
		printf("Arguments invalides\n");
		return (-1);
	}
	create_philo(&philo);
	while (philo.stop == 0)
	{
		check_eat(&philo);
		check_dead(&philo);
		usleep(150);
	}
	clean_exit(&philo);
}
