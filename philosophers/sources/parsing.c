/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouly <amouly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 16:58:29 by amouly            #+#    #+#             */
/*   Updated: 2023/02/12 11:11:29 by amouly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*void init_philo(t_philo_global *philo)
{
    philo->nb_philo = 0 ;
    philo->nb_fork = 0;
    philo->num_philo = 0;
    philo->time_to_eat = 0;
    philo->time_to_die = 0;
    philo->time_to_sleep = 0;
    philo->nb_of_eat = 0;
    
}*/
int check_digit(char **av, int ac)
{
    int i;
    int arg;

    arg = 1;
    while (arg < ac)
    {
        i = 0;
        while(av[arg][i])
        {
            if (av[arg][i] < 48 || av[arg][i] > 57)
                return (0);
            i++;
        }
        arg++;
    }
    return (1);
}

int parse_philo(t_philo_total *philo, char **av, int ac)
{
    if (av[1]== NULL || av[2] == NULL || av[3] == NULL || av[4] == NULL)
        return (0);
    if (ac == 6 && av[5] == NULL)
        return (0);
    if (!(check_digit(av, ac)))
    {    
        printf("arguments invalides\n");
        return (0);
    }
    philo->nb_philo = ft_atoi(av[1]);
    if (philo->nb_philo < 1)
        return (0);
    philo->nb_fork = philo->nb_philo;
    philo->time_to_die = ft_atoi(av[2]);
    philo->time_to_eat = ft_atoi(av[3]);
    philo->time_to_sleep = ft_atoi(av[4]);
    if (ac == 6)
        philo->nb_of_eat = ft_atoi(av[5]);
    else 
         philo->nb_of_eat = -1;
    philo->num_philo = 0;
    philo->philo_full = 0;
    philo->one_dead = 0;
    philo->list_of_full_philo = NULL;
    philo->th_philo = malloc(sizeof(pthread_t) * philo->nb_philo);
    if (philo->th_philo == NULL)
        return (0) ;
    philo->struct_philo = malloc(sizeof(t_philo_single) * philo->nb_philo);
    if (philo ->struct_philo == NULL)
        return (0);
    philo->fork_p = malloc(sizeof(pthread_mutex_t) * philo->nb_philo);
    if (philo->fork_p == NULL)
        return (0) ;
    return (1);
}