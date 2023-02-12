/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouly <amouly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 16:59:05 by amouly            #+#    #+#             */
/*   Updated: 2023/02/12 11:12:27 by amouly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"





int main (int ac, char **av)
{
    t_philo_total philo;

    if ((ac != 5 && ac != 6) || av == NULL)
    {
        printf("nombre d'argument invalide\n");
        return (-1);
    }
    if (!(parse_philo(&philo, av, ac)))
        return (-1);
    printf("NB DE PHILO AU DEBUT : %d\n", philo.nb_philo );
    create_philo(&philo);
    while (1)
    {
        usleep(50);
        check_eat(&philo);
        check_dead(&philo);
        if (philo.philo_full == philo.nb_philo || philo.one_dead == 1 )
            break;
    }
    printf("TOUS LES PHILO ONT MANGE");
    //system("leaks philo");
}
