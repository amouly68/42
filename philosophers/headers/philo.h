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

typedef struct s_philo_single
{
    int num_philo;
    int time_to_eat;
    int time_to_die;
    int time_to_sleep;
    int nb_of_eat;
    int ind_right_fork;
    int ind_left_fork;
    struct timeval start;
    struct timeval now;
    pthread_mutex_t *fork_p;

} t_philo_single;

typedef struct s_list_philo
{
    int index;
    struct s_list_philo *next;
} t_list_philo;

typedef struct s_philo_total
{
    int nb_philo;
    int philo_full;
    int nb_fork;
    int num_philo;
    int time_to_eat;
    int time_to_die;
    int time_to_sleep;
    int nb_of_eat;
    struct timeval start;
    t_list_philo *list_of_full_philo;
    pthread_t *th_philo;
    t_philo_single *struct_philo;
    pthread_mutex_t *fork_p;

} t_philo_total;



// parsing
int parse_philo(t_philo_total *philo, char **av, int ac);
void init_philo(t_philo_total *philo);

//create philo
void create_philo(t_philo_total *philo);

//utils
int check_and_add_philo_full(int index, t_list_philo **list_of_full_philo);
void print_time(struct timeval start, struct timeval end);
void check_sleep(struct timeval start, struct timeval begin ,int delay);
void print_case(t_philo_single *philo, int choice);

#endif
