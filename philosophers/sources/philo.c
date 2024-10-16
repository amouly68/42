/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouly <amouly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 17:54:56 by amouly            #+#    #+#             */
/*   Updated: 2023/02/18 14:24:14 by amouly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	sleep_and_think(t_philo_single *philo)
{
	print_case(philo, 3);
	check_wait(philo, philo->time_to_sleep);
	print_case(philo, 4);
	check_wait(philo, philo->time_to_eat - philo->time_to_sleep);
	if (philo->nb_philo % 2 == 1)
		check_wait(philo, philo->time_to_die - (2 * philo->time_to_eat) - 10);
}

void	*print_philo(void *param)
{
	t_philo_single	*philo;

	philo = param;
	if (philo->num_philo % 2 == 0)
		usleep(12000);
	while (philo->is_dead == 0)
	{
		pthread_mutex_lock(&(philo->fork_p[philo->ind_left_fork]));
		print_case(philo, 1);
		pthread_mutex_lock(&(philo->fork_p[philo->ind_right_fork]));
		print_case(philo, 1);
		print_case(philo, 2);
		check_wait(philo, philo->time_to_eat);
		if (philo->nb_of_eat > 0)
			philo->nb_of_eat--;
		pthread_mutex_unlock(&(philo->fork_p[philo->ind_left_fork]));
		pthread_mutex_unlock(&(philo->fork_p[philo->ind_right_fork]));
		sleep_and_think(philo);
	}
	return (NULL);
}

void	*print_philo_last(void *param)
{
	t_philo_single	*philo;

	philo = param;
	while (philo->is_dead == 0)
	{
		pthread_mutex_lock(&(philo->fork_p[philo->ind_right_fork]));
		print_case(philo, 1);
		if (philo->num_philo == 1)
		{
			check_wait(philo, philo->time_to_die + 1);
			return (NULL);
		}
		pthread_mutex_lock(&(philo->fork_p[philo->ind_left_fork]));
		print_case(philo, 1);
		print_case(philo, 2);
		check_wait(philo, philo->time_to_eat);
		if (philo->nb_of_eat > 0)
			philo->nb_of_eat--;
		pthread_mutex_unlock(&(philo->fork_p[philo->ind_right_fork]));
		pthread_mutex_unlock(&(philo->fork_p[philo->ind_left_fork]));
		sleep_and_think(philo);
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
	pthread_mutex_init(&(philo->mutex_protec), NULL);
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
