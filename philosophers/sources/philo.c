/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouly <amouly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 17:54:56 by amouly            #+#    #+#             */
/*   Updated: 2023/02/18 10:58:20 by amouly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	sleep_and_think(t_philo_single *philo)
{
	print_case(philo, 3);
	if (!(check_wait(philo, philo->time_to_sleep)))
		return (0);
	print_case(philo, 4);
	if (!(check_wait(philo, philo->time_to_eat - philo->time_to_sleep)))
		return (0);
	return (1);
}

void	*print_philo(void *param)
{
	t_philo_single	*philo;

	philo = param;
	if (philo->num_philo % 2 == 0)
		usleep(12500);
	while (philo->is_dead == 0)
	{
		if (philo->nb_of_eat == 0)
			return (NULL);
		//if (calc_time(philo->last_eat, philo->now) <= (philo->time_to_die
		//		* 0.8))
		pthread_mutex_lock(&(philo->fork_p[philo->ind_left_fork]));
		print_case(philo, 1);
		pthread_mutex_lock(&(philo->fork_p[philo->ind_right_fork]));
		print_case(philo, 1);
		print_case(philo, 2);
		if (!(check_wait(philo, philo->time_to_eat)))
			return (NULL);
		if (philo->nb_of_eat > 0)
			philo->nb_of_eat--;
		pthread_mutex_unlock(&(philo->fork_p[philo->ind_left_fork]));
		pthread_mutex_unlock(&(philo->fork_p[philo->ind_right_fork]));
		if (!(sleep_and_think(philo)))
			return (NULL);
	}
	return (NULL);
}

void	*print_philo_last(void *param)
{
	t_philo_single	*philo;


	philo = param;
	while (philo->is_dead == 0)
	{
		/*if (philo->num_philo % 2 == 1)
		{
			while (calc_time(philo->last_eat, philo->now) <= (philo->time_to_die
				* 0.6))
				{
					usleep (500);
					gettimeofday(&(philo->now), NULL);
				}
		}*/
		pthread_mutex_lock(&(philo->fork_p[philo->ind_right_fork]));
		print_case(philo, 1);
		if (philo->num_philo == 1)
		{
			if (!(check_wait(philo, philo->time_to_die + 1)))
				return (NULL);
		}
		pthread_mutex_lock(&(philo->fork_p[philo->ind_left_fork]));
		print_case(philo, 1);
		print_case(philo, 2);
		if (!(check_wait(philo, philo->time_to_eat)))
			return (NULL);
		if (philo->nb_of_eat > 0)
			philo->nb_of_eat--;
		pthread_mutex_unlock(&(philo->fork_p[philo->ind_right_fork]));
		pthread_mutex_unlock(&(philo->fork_p[philo->ind_left_fork]));
		if (!(sleep_and_think(philo)))
			return (NULL);
	}
	return (NULL);
}

void	fill_struct_philo(t_philo_total *philo, t_philo_single *struct_philo)
{
	struct_philo->num_philo = philo->num_philo;
	struct_philo->nb_philo = philo->nb_philo;
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
	struct_philo->is_dead = 0;
	struct_philo->last_eat = philo->start;
	struct_philo->philo_total = philo;
}

void	create_philo(t_philo_total *philo)
{
	int	i;

	
	i = 0;
	while (i < (philo->nb_philo))
	{
		pthread_mutex_init(&(philo->fork_p[i]), NULL);
		i++;
	}
	pthread_mutex_init(&(philo->mutex_dead), NULL);
	i = 0;
	gettimeofday(&(philo->start), NULL);
	while (i < (philo->nb_philo) - 1)
	{
		philo->num_philo++;
		fill_struct_philo(philo, &(philo->struct_philo[i]));
		pthread_create(&(philo->th_philo[i]), NULL, &print_philo,
				&(philo->struct_philo[i]));
		i++;
	}
	philo->num_philo++;
	fill_struct_philo(philo, &(philo->struct_philo[i]));
	pthread_create(&(philo->th_philo[i]), NULL, &print_philo_last,
			&(philo->struct_philo[i]));

}
