/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouly <amouly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 17:54:56 by amouly            #+#    #+#             */
/*   Updated: 2023/02/10 16:15:47 by amouly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


void    *print_philo(void *param)
{
    t_philo_single *philo;
    int num;
    
    philo = param;
    num = philo->num_philo;
    gettimeofday(&(philo->end), NULL);
    print_time(philo->start, philo->end);
    printf("Philo num %d is alive\n", num); 
    while (1)
   {
        if (philo->nb_of_eat == 0)
        {
            gettimeofday(&(philo->end), NULL);
            print_time(philo->start, philo->end);
            printf("Philo num %d a fini de manger\n", num);
            return (NULL);
        }
        pthread_mutex_lock(&(philo->fork_p[philo->ind_left_fork]));
        gettimeofday(&(philo->end), NULL);
        print_time(philo->start, philo->end);
        printf("Philo num %d a pris la fourchette num %d \n", num, philo->ind_left_fork );
        pthread_mutex_lock(&(philo->fork_p[philo->ind_right_fork]));
        gettimeofday(&(philo->end), NULL);
        print_time(philo->start, philo->end);
        printf("Philo num %d a pris la fourchette num %d \n", num, philo->ind_right_fork );
        gettimeofday(&(philo->end), NULL);
        print_time(philo->start, philo->end);
        printf("Philo num %d mange \n", num);
        check_sleep(philo->start, philo->end, philo->time_to_eat);
        if (philo->nb_of_eat > 0)
            philo->nb_of_eat--;
        pthread_mutex_unlock(&(philo->fork_p[philo->ind_left_fork]));
        pthread_mutex_unlock(&(philo->fork_p[philo->ind_right_fork]));
        gettimeofday(&(philo->end), NULL);
        print_time(philo->start, philo->end);
        printf("Philo num %d dort \n", num);
        gettimeofday(&(philo->end), NULL);
        print_time(philo->start, philo->end);
        printf("Philo num %d pense \n", num);
        usleep(300);
   }
    return (NULL); 
}
void    *print_philo_last(void *param)
{
    t_philo_single *philo;
    int num;
    
    philo = param;
    num = philo->num_philo;
    gettimeofday(&(philo->end), NULL);
    print_time(philo->start, philo->end);
    printf("Philo num %d is alive\n", num); 
    while (1)
   {
        if (philo->nb_of_eat == 0)
        {
            gettimeofday(&(philo->end), NULL);
            print_time(philo->start, philo->end);
            printf("Philo num %d a fini de manger\n", num);
            return (NULL);
        }
        pthread_mutex_lock(&(philo->fork_p[philo->ind_right_fork]));
        gettimeofday(&(philo->end), NULL);
        print_time(philo->start, philo->end);
        printf("Philo num %d  a pris la fourchette num %d \n", num, philo->ind_left_fork );
        pthread_mutex_lock(&(philo->fork_p[philo->ind_left_fork]));
        gettimeofday(&(philo->end), NULL);
        print_time(philo->start, philo->end);
        printf("Philo num %d a pris la fourchette num %d \n", num, philo->ind_right_fork );
        gettimeofday(&(philo->end), NULL);
        print_time(philo->start, philo->end);
        printf("Philo num %d mange \n", num);
        if (philo->nb_of_eat > 0)
            philo->nb_of_eat--;
        pthread_mutex_unlock(&(philo->fork_p[philo->ind_right_fork]));
        pthread_mutex_unlock(&(philo->fork_p[philo->ind_left_fork]));
        gettimeofday(&(philo->end), NULL);
        print_time(philo->start, philo->end);
        printf("Philo num %d dort \n", num);
        gettimeofday(&(philo->end), NULL);
        print_time(philo->start, philo->end);
        printf("Philo num %d pense \n", num);
        usleep(300);
   }
    return (NULL); 
}

void fill_struct_philo(t_philo_total *philo, t_philo_single *struct_philo)
{
    struct_philo->num_philo = philo->num_philo;
    struct_philo->time_to_eat = philo->time_to_eat;
    struct_philo->time_to_die = philo->time_to_die;
    struct_philo->time_to_sleep = philo->time_to_sleep;
    struct_philo->nb_of_eat = philo->nb_of_eat;
    struct_philo->ind_left_fork = philo->num_philo - 1;
    if (philo->num_philo == philo->nb_philo)
        struct_philo->ind_right_fork = 0;
    else 
        struct_philo->ind_right_fork = philo->num_philo;
    struct_philo->fork_p = philo->fork_p;
    struct_philo->start = philo->start;
    
}

void create_philo(t_philo_total *philo)
{
    int i;
    
    i = 0;
    while(i < (philo->nb_philo))
    {
        pthread_mutex_init(&(philo->fork_p[i]), NULL);
        i++;
    }
    i = 0;
    gettimeofday(&(philo->start), NULL);
    while(i < (philo->nb_philo) -1 )
    {
        philo->num_philo ++;
        fill_struct_philo(philo, &(philo->struct_philo[i]));
        pthread_create(&(philo->th_philo[i]), NULL, &print_philo, &(philo->struct_philo[i]));
        i++;
        usleep(200);
    }
        philo->num_philo ++;
        fill_struct_philo(philo, &(philo->struct_philo[i]));
        pthread_create(&(philo->th_philo[i]), NULL, &print_philo_last, &(philo->struct_philo[i]));
       
}