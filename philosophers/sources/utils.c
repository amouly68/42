/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouly <amouly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 11:24:34 by amouly            #+#    #+#             */
/*   Updated: 2023/02/15 13:30:50 by amouly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	calc_time(struct timeval start, struct timeval end)
{
	int	time;

	time = (end.tv_sec - start.tv_sec) * 1000;
	time = time + ((end.tv_usec - start.tv_usec) / 1000);
	return (time);
}

void	if_dead(t_philo_single *philo, int time_calc)
{
	if (calc_time(philo->last_eat, philo->now) >= philo->time_to_die
		&& philo->is_dead == 0)
	{
		//pthread_mutex_lock(&(philo->mutex_isdead));
		philo->is_dead = 1;
		//pthread_mutex_unlock(&(philo->mutex_isdead));
		printf("%d %d died\n", time_calc, philo->num_philo);
	}
}

void	print_case(t_philo_single *philo, int choice)
{
	int	time_calc;

	gettimeofday(&(philo->now), NULL);
	time_calc = calc_time(philo->start, philo->now);
	//pthread_mutex_lock(&(philo->mutex_isdead));
	if_dead(philo, time_calc);
	if (philo->is_dead == 0)
	{
		if (choice == 1)
			printf("%d %d has taken a fork\n", time_calc, philo->num_philo);
		if (choice == 2)
		{
			printf("%d %d is eating\n", time_calc, philo->num_philo);
			philo->last_eat = philo->now;
		}
		if (choice == 3)
			printf("%d %d is sleeping\n", time_calc, philo->num_philo);
		if (choice == 4)
			printf("%d %d is thinking\n", time_calc, philo->num_philo);
		if (choice == 5)
			printf("%d %d died\n", time_calc, philo->num_philo);
	}
	//pthread_mutex_unlock(&(philo->mutex_isdead));
	usleep(150);
}

void	clean_exit (t_philo_total	*philo)
{
	int i;

	i = 0;
	while (i < (philo->nb_philo))
	{
		pthread_join(philo->th_philo[i], NULL);
		i++;
	}
	i = 0;
	while (i < (philo->nb_philo))
	{
		pthread_mutex_destroy (&(philo->fork_p[i]));
		i++;
	}
	//pthread_mutex_destroy (&(philo->mutex_nbofeat));
	free (philo->th_philo);
	free (philo->struct_philo);
	free (philo->fork_p);
}
