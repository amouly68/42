/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouly <amouly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 16:59:05 by amouly            #+#    #+#             */
/*   Updated: 2023/02/09 14:11:01 by amouly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main (int ac, char **av)
{
    t_philo_global philo;
    
    
    if ((ac != 5 && ac != 6) || av == NULL)
    {
        ft_printf("nombre d'argument invalide\n");
        return (-1);
    }
    if (!(parse_philo(&philo, av, ac)))
        return (-1);
    create_philo(&philo);
    while (1);
}
