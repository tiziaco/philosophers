/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiacovel <tiacovel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 11:47:39 by tiacovel          #+#    #+#             */
/*   Updated: 2024/02/16 11:35:48 by tiacovel         ###   ########.fr       */
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
# include <errno.h>

# define INVALID_PARAMS ((t_parms){.is_valid = false})
# define PARMS_ERROR 		1
# define ALLOCATION_ERROR	2

# define RST    "\033[0m"      /* Reset to default color */
# define RED	"\033[1;31m"   /* Bold Red */
# define G      "\033[1;32m"   /* Bold Green */

typedef struct timeval	t_time;
typedef struct s_data	t_data;
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

typedef enum e_action
{
	LOCK,
	UNLOCK,
	INIT,
	DESTROY,
	CREATE,
	JOIN,
	DETACH,
}	t_action;

typedef enum e_time_unit
{
	MILLISECONDS,
	MICROSECONDS
}	t_time_unit;

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
	t_mutex	*fork_mutex;
}	t_fork;

typedef struct s_philo
{
	int			id;
	bool		is_alive;
	bool		is_full;
	int			meals_counter;
	int			last_eat_time;
	t_fork		*left_fork;
	t_fork		*right_fork;
	t_data		*data;
	pthread_t	thread_id;
	t_mutex		*philo_mutex;
}	t_philo;

typedef struct s_data
{
	t_parms		parms;
	t_philo		**philos;
	t_fork		**forks;
	t_time		start_time;
	bool		simulation_ended;
	bool		all_threads_ready;
	pthread_t	monitor;
	t_mutex		*table_mutex;
	t_mutex		*write_mutex;
}	t_data;

/* Time functions */
long long get_elapsed_time(t_time start, t_time end, t_time_unit unit);
void	precise_usleep(long usec);

/* Utility functions */
int		is_num(const char *str);
int		ft_atoi(const char *str);

/* Philosopher functions */
t_philo	**init_philosphers(t_data *data);
void	free_philosophers(t_philo **philosphers);

/* Forks functions*/
t_fork	**init_forks(int philo_nbr);
void	free_forks(t_fork **forks);

/* Runtime functions */
t_data	*init_data(int argc, char **argv);
void	free_data(t_data *data);
void	*start_routine();
void	error_exit(const char *error);

/* Handlers */
void	mutex_handler(t_mutex *mutex, t_action action);

/* Getters and setters */
bool	is_full(t_philo *philo);

/* Test functions*/
void	print_parms(t_parms parms);
void	print_philo_ids(t_philo **philosophers);

#endif