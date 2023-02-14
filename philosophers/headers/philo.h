/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouly <amouly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 15:34:04 by amouly            #+#    #+#             */
/*   Updated: 2023/01/26 10:18:24 by amouly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include "libft.h"
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_philo_single
{
	int					num_philo;
	int					time_to_eat;
	int					time_to_die;
	int					time_to_sleep;
	int					nb_of_eat;
	int					ind_right_fork;
	int					ind_left_fork;
	int					is_dead;
	struct timeval		start;
	struct timeval		now;
	struct timeval		last_eat;
	pthread_mutex_t		*fork_p;

}						t_philo_single;

typedef struct s_list_philo
{
	int					index;
	struct s_list_philo	*next;
}						t_list_philo;

typedef struct s_philo_total
{
	long				nb_philo;
	int					philo_full;
	int					nb_fork;
	long				num_philo;
	long				time_to_eat;
	long				time_to_die;
	long				time_to_sleep;
	long				nb_of_eat;
	int					one_dead;
	struct timeval		start;
	t_list_philo		*list_of_full_philo;
	pthread_t			*th_philo;
	t_philo_single		*struct_philo;
	pthread_mutex_t		*fork_p;

}						t_philo_total;

// parsing
int						parse_philo(t_philo_total *philo, char **av, int ac);

//create philo
void					create_philo(t_philo_total *philo);

//utils
int						check_and_add_philo_full(int index,
							t_list_philo **list_of_full_philo);
void					print_time(struct timeval start, struct timeval end);
void					print_case(t_philo_single *philo, int choice);
int						calc_time(struct timeval start, struct timeval end);

// checker
void					check_eat(t_philo_total *philo);
void					check_dead(t_philo_total *philo);
int						check_wait(t_philo_single *philo, int delay);

#endif
