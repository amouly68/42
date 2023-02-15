/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouly <amouly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 16:59:05 by amouly            #+#    #+#             */
/*   Updated: 2023/02/15 13:31:03 by amouly           ###   ########.fr       */
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
	while (philo.one_dead != 1 && philo.philo_full != philo.nb_philo)
	{
		check_eat(&philo);
		check_dead(&philo);
		/*if (philo.philo_full == philo.nb_philo)
			break ;
		if (philo.one_dead == 1)
			break ;*/
	}
	/*while (philo.one_dead == 0)
	{
		check_eat(&philo);
		check_dead(&philo);
		if (philo.philo_full == philo.nb_philo)
			break ;
		if (philo.one_dead == 1)
			break ;
	}*/
	clean_exit (&philo);
}
