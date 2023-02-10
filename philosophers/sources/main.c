/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouly <amouly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 16:59:05 by amouly            #+#    #+#             */
/*   Updated: 2023/02/10 15:25:48 by amouly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main (int ac, char **av)
{
    t_philo_total philo;
    int i;

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
        usleep(300);
        i = 0;
        while (i < philo.nb_philo)
        {
           // printf("Il reste %d repas au philo num %d\n", philo.struct_philo[i].nb_of_eat, philo.struct_philo[i].num_philo);
            if (philo.struct_philo[i].nb_of_eat == 0)
            {
                pthread_join((philo.th_philo[i]), NULL);
                if (check_and_add_philo_full(i, &(philo.list_of_full_philo)))
                {
                   philo.philo_full++;
                   printf("NB DE PHILO FULL : %d\n", philo.philo_full );
                }
            }
            i++;
        }
        if (philo.philo_full == philo.nb_philo)
            break;
    }
    printf("TOUS LES PHILO ONT MANGE");
}
