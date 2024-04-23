/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiacovel <tiacovel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 11:47:39 by tiacovel          #+#    #+#             */
/*   Updated: 2024/04/23 15:37:12 by tiacovel         ###   ########.fr       */
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

// # define INVALID_PARAMS ((t_parms){.is_valid = false})
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
	int		max_meals;
	bool	is_valid;
}	t_parms;

typedef struct s_fork
{
	int		id;
	t_mutex	fork_mutex;
}	t_fork;

typedef struct s_philo
{
	int			id;
	bool		is_alive;
	bool		is_full;
	int			meals_counter;
	long long	last_eat_time;
	t_fork		*left_fork;
	t_fork		*right_fork;
	t_data		*data;
	pthread_t	thread_id;
	t_mutex		philo_mutex;
}	t_philo;

typedef struct s_data
{
	t_parms		parms;
	t_philo		**philos;
	t_fork		**forks;
	long long	start_time;
	bool		sim_is_running;
	bool		all_threads_ready;
	int			threads_counter;
	pthread_t	monitor;
	t_mutex		table_mutex;
	t_mutex		write_mutex;
}	t_data;

/* Time functions */
long long	get_elapsed_time(t_philo *philo);
long long	get_time_ms(void);
void		precise_usleep(long long msec, t_data *data);

/* Utility functions */
int			is_num(const char *str);
int			ft_atoi(const char *str);

/* Philosopher functions */
t_philo		**init_philosphers(t_data *data);
void		free_philosophers(t_philo **philosphers);

/* Actions */
void		assign_forks(t_philo *philo, t_fork **forks, int philo_position);
void		philo_sleep(t_philo *philo);
void		eat(t_philo *philo);
void		think(t_philo *philo, bool pre_simulation);

/* Forks functions*/
t_fork		**init_forks(int philo_nbr);
void		free_forks(t_fork **forks);

/* Runtime functions */
void		start_dinner_simulation(t_data *data);
t_data		*init_data(int argc, char **argv);
void		free_data(t_data *data);
//void		*start_routine();
void		error_exit(const char *error);
void		*table_manager(void *arg);

/* Handlers */
void		mutex_handler(t_mutex *mutex, t_action action);
void		thread_handler(pthread_t *thread, void *(*foo)(void *),
				void *data, t_action action);

/* Getters and setters */
bool		philo_is_full(t_philo *philo);
bool		sim_is_running(t_data *data);
bool		all_threads_ready(t_data *data);

void		set_last_meal_time(t_philo *philo);
void		increase_meals_counter(t_philo *philo);
void		set_simulation_ended(t_data *data);
void		set_all_threads_ready(t_data *data);
void		increase_thread_counter(t_data *data);

/* Sync utils */
void		wait_all_threads(t_data *data);
bool		all_threads_running(t_data *data);
void		de_synchronize_philos(t_philo *philo);

/* Print functions*/
void		print_status(t_philo_status status, t_philo *philo);
void		print_parms(t_parms parms);
void		print_philo_ids(t_philo **philosophers);

#endif