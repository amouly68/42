/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouly <amouly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 16:58:29 by amouly            #+#    #+#             */
/*   Updated: 2023/02/08 15:26:03 by amouly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void init_philo(t_philo_global *philo)
{
    philo->nb_philo = 0 ;
    philo->nb_fork = 0;
    philo->num_philo = 0;
    philo->time_to_eat = 0;
    philo->time_to_die = 0;
    philo->time_to_sleep = 0;
    philo->nb_of_eat = 0;
    
}


int parse_philo(t_philo_global *philo, char **av, int ac)
{
    if (av[1]== NULL || av[2] == NULL || av[3] == NULL || av[4] == NULL)
        return (0);
    if (ac == 6 && av[5] == NULL)
        return (0);
    philo->nb_philo = ft_atoi(av[1]);
    if (philo->nb_philo < 1)
        return (0);
    philo->nb_fork = philo->nb_philo;
    philo->time_to_die = ft_atoi(av[2]);
    philo->time_to_eat = ft_atoi(av[3]);
    philo->time_to_sleep = ft_atoi(av[4]);
    if (ac == 6)
        philo->nb_of_eat = ft_atoi(av[5]);
    return (1);
}