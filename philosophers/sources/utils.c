/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouly <amouly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 11:24:34 by amouly            #+#    #+#             */
/*   Updated: 2023/02/12 11:46:34 by amouly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


int calc_time(struct timeval start, struct timeval end)
{
    int time;

    time = (end.tv_sec - start.tv_sec) * 1000;
    time = time + ((end.tv_usec - start.tv_usec) / 1000);
    return (time);
}

void print_time(struct timeval start, struct timeval end)
{
    printf("%d ms ", calc_time(start, end));
}


int check_wait(t_philo_single *philo ,int delay)
{
    struct timeval actual_time;
    
    actual_time = philo->now;
    while(calc_time(philo->start, actual_time) <= (calc_time(philo->start, philo->now) + delay ))
    {
        usleep (250);
        if (calc_time(philo->last_eat, actual_time) > philo->time_to_die)
        {
            philo->is_dead = 1;
            printf("%d ms %d died\n", calc_time(philo->start, actual_time), philo->num_philo);
            return(0);
        }
        gettimeofday(&actual_time, NULL);
        
    }
    return (1);
}

void print_case(t_philo_single *philo, int choice)
{
    gettimeofday(&(philo->now), NULL);
    if (choice == 1)
        printf("%d ms %d has taken a fork\n", calc_time(philo->start, philo->now), philo->num_philo);
    if (choice == 2)
    {
       /* if (calc_time(philo->last_eat, philo->now) > philo->time_to_die)
        {
            philo->is_dead = 1;
            printf("%d ms %d died\n", calc_time(philo->start, philo->now), philo->num_philo);
            return;
        }*/
        printf("%d ms %d is eating\n", calc_time(philo->start, philo->now), philo->num_philo);
        philo->last_eat = philo->now;
    }
    if (choice == 3)
        printf("%d ms %d is sleeping\n", calc_time(philo->start, philo->now), philo->num_philo);
    if (choice == 4)
        printf("%d ms %d is thinking\n", calc_time(philo->start, philo->now), philo->num_philo);
    if (choice == 5)
        printf("%d ms %d died\n", calc_time(philo->start, philo->now), philo->num_philo);
    if (choice == 6)
        printf("%d ms %d is done eating\n", calc_time(philo->start, philo->now), philo->num_philo);
    if (choice == 7)
        printf("%d ms %d is alive\n", calc_time(philo->start, philo->now), philo->num_philo);
}