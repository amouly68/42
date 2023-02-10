/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouly <amouly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 11:24:34 by amouly            #+#    #+#             */
/*   Updated: 2023/02/10 16:18:06 by amouly           ###   ########.fr       */
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
        printf("nouvel index a rajouter : %d\n", index);
        new->next = (*list_of_full_philo);
        *list_of_full_philo = new;
        return (1);
    }   
    return (0);
}

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


void check_sleep(struct timeval start, struct timeval begin ,int delay)
{
    struct timeval actual_time;
    
    actual_time = begin;
    while(calc_time(start, actual_time) <= (calc_time(start, begin) + delay ))
    {
        usleep (1000);
        // check si qqn est mort
        gettimeofday(&actual_time, NULL);
        printf("temps d'attente : %d ms \n", calc_time(start, actual_time) - (calc_time(start, begin)));
    }
    printf("LE SLEEP EST FINI\n");
    
}