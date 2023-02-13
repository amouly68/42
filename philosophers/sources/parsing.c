/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouly <amouly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 16:58:29 by amouly            #+#    #+#             */
/*   Updated: 2023/02/13 16:03:07 by amouly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	ft_atoi_philo(const char *str)
{
	int	i;
	int	neg;
	long num;

	i = 0;
	num = 0;
	neg = 1;
	while (str[i] != '\0' && (str[i] == 32 || str[i] == '\t'
			|| str[i] == '\r' || str[i] == '\n'
			|| str[i] == '\v' || str[i] == '\f'))
		i++;
	if (str[i] != '\0' && (str[i] == '+' || str[i] == '-'))
	{
		if (str[i] == '-')
			neg = -1;
		i++;
	}
	while (str[i] != '\0' && (str[i] >= '0' && str[i] <= '9' ))
	{
		num = (num * 10) + (str[i] - 48);
        if (num > INT32_MAX)
            return (-1);
		i++;
	}		
	num = num * neg;
	return (num);
}

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
    philo->nb_philo = ft_atoi_philo(av[1]);
    if (philo->nb_philo < 1)
        return (0);
    philo->nb_fork = philo->nb_philo;
    philo->time_to_die = ft_atoi_philo(av[2]);
    philo->time_to_eat = ft_atoi_philo(av[3]);
    philo->time_to_sleep = ft_atoi_philo(av[4]);
    if (ac == 6)
        philo->nb_of_eat = ft_atoi_philo(av[5]);
    else 
         philo->nb_of_eat = -1;
    if (philo->time_to_die == -1 || philo->time_to_eat == -1
        || philo->time_to_sleep == -1 || philo->nb_philo == -1
        || philo->nb_of_eat == -1 )
    {    
        printf("arguments invalides\n");
        return (0);
    }
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