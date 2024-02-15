/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiacovel <tiacovel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 11:47:39 by tiacovel          #+#    #+#             */
/*   Updated: 2024/02/15 11:08:32 by tiacovel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <pthread.h>
# include <limits.h>
# include <stdbool.h>
# include <sys/time.h>

# define INVALID_PARAMS ((t_parms){.is_valid = false})
# define PARMS_ERROR 		1
# define ALLOCATION_ERROR	2

typedef struct timeval	t_time;
typedef pthread_mutex_t	t_mutex;

typedef enum e_status
{
	EATING,
	SLEEPING,
	THINKING,
	TAKE_FIRST_FORK,
	TAKE_SECOND_FORK,
	DIED,
}	t_philo_status;

typedef struct s_parms
{
	int		phils_nbr;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	int		meals_counter;
	bool	is_valid;
}	t_parms;

typedef struct s_fork
{
	int		id;
	t_mutex	fork;
}	t_fork;

typedef struct s_philo
{
	int			id;
	bool		is_alive;
	int			meals_counter;
	int			last_eat_time;
	t_fork		*left_fork;
	t_fork		*right_fork;
	pthread_t	thread_id;
}	t_philo;

typedef struct s_data
{
	t_parms		parms;
	t_philo		**philos;
	t_fork		**forks;
	int			start_time;
	bool		simulation_ended;
	bool		all_threads_ready;
	pthread_t	monitor;
}	t_data;

/* Time functions */
int		elapsed_time_ms(t_time start_time, t_time end_time);
void	precise_usleep(long usec);

/* Utility functions */
int		is_num(const char *str);

/* Philosopher functions */
t_philo	**init_philosphers(t_parms parms);
void	free_philosophers(t_philo **philosphers);

/* Forks functions*/
t_mutex	**init_forks(int philo_nbr);
void	free_forks(t_mutex **forks);

/* Runtime functions */
void	*start_routine();
int		ft_atoi(const char *str);

/* Test functions*/
void	print_parms(t_parms parms);
void	print_philo_ids(t_philo **philosophers);

#endif