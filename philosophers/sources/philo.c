/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouly <amouly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 17:54:56 by amouly            #+#    #+#             */
/*   Updated: 2023/02/08 16:39:12 by amouly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

pthread_mutex_t *fork_p;

void    *print_philo(void *param)
{
    t_philo_single *philo;
    int num;
    
    philo = param;
    num = philo->num_philo;
   // printf("Philo num %d is alive\n", num); 
    pthread_mutex_lock(&fork_p[philo->ind_left_fork]);
    printf("Philo num %d  a pris la fourchette num %d \n", num, philo->ind_left_fork );
    pthread_mutex_unlock(&(fork_p[philo->ind_left_fork]));
    pthread_mutex_lock(&fork_p[philo->ind_right_fork]);
    printf("Philo num %d a pris la fourchette num %d \n", num, philo->ind_right_fork );
    pthread_mutex_unlock(&fork_p[philo->ind_right_fork]);
    return (NULL); 
}
void    *print_philo_last(void *param)
{
    t_philo_single *philo;
    int num;
    
    philo = param;
    num = philo->num_philo;
   // printf("Philo num %d is alive\n", num); 
    pthread_mutex_lock(&(fork_p[philo->ind_right_fork]));
    printf("Philo num %d a pris la fourchette num %d \n", num, philo->ind_right_fork );
    pthread_mutex_unlock(&(fork_p[philo->ind_right_fork]));
    pthread_mutex_lock(&(fork_p[philo->ind_left_fork]));
    printf("Philo num %d  a pris la fourchette num %d \n", num, philo->ind_left_fork );
    pthread_mutex_unlock(&fork_p[philo->ind_left_fork]);
    return (NULL); 
}

void fill_struct_philo(t_philo_global *philo, t_philo_single *struct_philo)
{
    struct_philo->num_philo = philo->num_philo;
    struct_philo->time_to_eat = philo->time_to_eat;
    struct_philo->time_to_die = philo->time_to_die;
    struct_philo->time_to_sleep = philo->time_to_sleep;
    struct_philo->nb_of_eat = philo->nb_of_eat;
    struct_philo->ind_left_fork = philo->num_philo - 1;
    struct_philo->ind_right_fork = philo->num_philo;
    
}

void create_philo(t_philo_global *philo)
{
    pthread_t *th_philo;
    t_philo_single *struct_philo;
    //pthread_mutex_t *fork;
    int i;
    
    i = 0;
    th_philo = malloc(sizeof(pthread_t) * philo->nb_philo);
    if (th_philo == NULL)
        return ;
    struct_philo = malloc(sizeof(t_philo_single) * philo->nb_philo);
    if (struct_philo == NULL)
        return ;
    fork_p = malloc(sizeof(pthread_mutex_t) * philo->nb_philo);
    if (fork_p == NULL)
        return ;
    while(i < (philo->nb_philo))
    {
        pthread_mutex_init(&fork_p[i], NULL);
        i++;
    }
    i = 0;
    while(i < (philo->nb_philo) -1 )
    {
        philo->num_philo ++;
        fill_struct_philo(philo, &struct_philo[i]);
        pthread_create(&(th_philo[i]), NULL, &print_philo, &struct_philo[i]);
        i++;
    }
         philo->num_philo ++;
        fill_struct_philo(philo, &struct_philo[i]);
        pthread_create(&(th_philo[i]), NULL, &print_philo_last, &struct_philo[i]);
}