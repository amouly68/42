/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouly <amouly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 15:34:04 by amouly            #+#    #+#             */
/*   Updated: 2023/01/26 10:18:24 by amouly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include "libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
#include <sys/time.h>

typedef struct s_philo_global
{
    int nb_philo;
    int nb_fork;
    int num_philo;
    int time_to_eat;
    int time_to_die;
    int time_to_sleep;
    int nb_of_eat;

} t_philo_global;

typedef struct s_philo_single
{
    int num_philo;
    int time_to_eat;
    int time_to_die;
    int time_to_sleep;
    int nb_of_eat;
    int ind_right_fork;
    int ind_left_fork;

} t_philo_single;

// parsing
int parse_philo(t_philo_global *philo, char **av, int ac);
void init_philo(t_philo_global *philo);

//create philo
void create_philo(t_philo_global *philo);

#endif
