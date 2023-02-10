/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouly <amouly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 11:24:34 by amouly            #+#    #+#             */
/*   Updated: 2023/02/10 12:29:38 by amouly           ###   ########.fr       */
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