/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouly <amouly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 10:51:04 by amouly            #+#    #+#             */
/*   Updated: 2023/02/13 14:43:01 by amouly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int check_and_add_philo_full(int index, t_list_philo **list_of_full_philo)
{
    t_list_philo *temp;
    t_list_philo *new;
    
    temp = *(list_of_full_philo);
    if (list_of_full_philo == NULL)
        return (0);
    while (temp)
    {
        if (temp->index == index)
            return (0);
        temp = temp->next;
    }
    if (temp == NULL)
    {
        new = malloc(sizeof(t_list_philo));
        if (new == NULL)
            return (0);
        new->index = index;
        //printf("nouvel index a rajouter : %d\n", index);
        new->next = (*list_of_full_philo);
        *list_of_full_philo = new;
        return (1);
    }   
    return (0);
}

void check_eat(t_philo_total *philo)
{
    int i;
    
    i = 0;
    while (i < philo->nb_philo)
    {
       
        if (philo->struct_philo[i].nb_of_eat == 0)
        {
          //  pthread_join((philo->th_philo[i]), NULL);
            if (check_and_add_philo_full(i, &(philo->list_of_full_philo)))
            {
                philo->philo_full++;
                //printf("%d ms : NB DE PHILO FULL : %d\n", calc_time(philo->struct_philo[i].start, philo->struct_philo[i].now), philo->philo_full );
            }
        }
        i++;
    }
}

void check_dead(t_philo_total *philo)
{
    int i;
    
    i = 0;
    while (i < philo->nb_philo)
    {
        if (philo->struct_philo[i].is_dead == 1)
            philo->one_dead = 1;
        i++;
    }
}


int check_wait(t_philo_single *philo ,int delay)
{
    struct timeval actual_time;
    
    actual_time = philo->now;
    while(calc_time(philo->start, actual_time) < (calc_time(philo->start,philo->now) + delay ))
    {
        usleep (250);
        if (calc_time(philo->last_eat, actual_time) >= philo->time_to_die)
        {
            philo->is_dead = 1;
            printf("%d %d died\n", calc_time(philo->start, actual_time), philo->num_philo);
            return(0);
        }
        gettimeofday(&actual_time, NULL);
        
    }
    return (1);
}


