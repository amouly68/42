/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouly <amouly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 17:54:56 by amouly            #+#    #+#             */
/*   Updated: 2023/02/08 17:04:05 by amouly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


void    *print_philo(void *param)
{
    t_philo_single *philo;
    int num;
    
    philo = param;
    num = philo->num_philo;
    printf("Philo num %d is alive\n", num); 
    pthread_mutex_lock(&(philo->fork_p[philo->ind_left_fork]));
    printf("Philo num %d  a pris la fourchette num %d \n", num, philo->ind_left_fork );
    //pthread_mutex_unlock(&(fork_p[philo->ind_left_fork]));
    pthread_mutex_lock(&(philo->fork_p[philo->ind_right_fork]));
    printf("Philo num %d a pris la fourchette num %d \n", num, philo->ind_right_fork );
   // pthread_mutex_unlock(&fork_p[philo->ind_right_fork]);
    return (NULL); 
}
void    *print_philo_last(void *param)
{
    t_philo_single *philo;
    int num;
    
    philo = param;
    num = philo->num_philo;
   // printf("Philo num %d is alive\n", num); 
    pthread_mutex_lock(&(philo->fork_p[philo->ind_right_fork]));
    printf("Philo num %d a pris la fourchette num %d \n", num, philo->ind_right_fork );
    pthread_mutex_unlock(&(philo->fork_p[philo->ind_right_fork]));
    pthread_mutex_lock(&(philo->fork_p[philo->ind_left_fork]));
    printf("Philo num %d  a pris la fourchette num %d \n", num, philo->ind_left_fork );
    pthread_mutex_unlock(&(philo->fork_p[philo->ind_left_fork]));
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
    struct_philo->fork_p = philo->fork_p;
    
}

void create_philo(t_philo_global *philo)
{
    int i;
    
    i = 0;
    while(i < (philo->nb_philo))
    {
        pthread_mutex_init(&(philo->fork_p[i]), NULL);
        i++;
    }
    i = 0;
    while(i < (philo->nb_philo) -1 )
    {
        philo->num_philo ++;
        fill_struct_philo(philo, &(philo->struct_philo[i]));
        pthread_create(&(philo->th_philo[i]), NULL, &print_philo, &(philo->struct_philo[i]));
        i++;
    }
        philo->num_philo ++;
        fill_struct_philo(philo, &(philo->struct_philo[i]));
        pthread_create(&(philo->th_philo[i]), NULL, &print_philo_last, &(philo->struct_philo[i]));
}