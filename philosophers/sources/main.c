/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouly <amouly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 16:59:05 by amouly            #+#    #+#             */
/*   Updated: 2023/02/10 12:15:26 by amouly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main (int ac, char **av)
{
    t_philo_total philo;
    int i;

    if ((ac != 5 && ac != 6) || av == NULL)
    {
        ft_printf("nombre d'argument invalide\n");
        return (-1);
    }
    if (!(parse_philo(&philo, av, ac)))
        return (-1);
    ft_printf("NB DE PHILO AU DEBUT : %d\n", philo.nb_philo );
    create_philo(&philo);
    while (1)
    {
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
                   ft_printf("NB DE PHILO FULL : %d\n", philo.philo_full );
                }
            }
            i++;
        }
        if (philo.philo_full == philo.nb_philo)
            break;
    }
    ft_printf("TOUS LES PHILO ONT MANGE");
}
