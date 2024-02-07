/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiacovel <tiacovel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 11:47:39 by tiacovel          #+#    #+#             */
/*   Updated: 2024/02/07 17:47:31 by tiacovel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <pthread.h>
//# include <limits.h>
# include <stdbool.h>
# include <sys/time.h>

# define INVALID_PARAMS ((t_parms){ .is_valid = false })
# define PARMS_ERROR 		1
# define ALLOCATION_ERROR	2

typedef struct timeval t_time;

typedef struct s_parms
{
	int		phils_nbr;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	int		nbr_must_eat;
	bool	is_valid;
}	t_parms;

typedef struct s_philo
{
	int	id;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int nbr_must_eat;
	int	last_eat_time;
}	t_philo;

/* Time functions */
int		elapsed_time(t_time start_time, t_time end_time);

/* Utility functions */
int		is_num(const char *str);

/* Philosopher functions */
t_philo	**init_philosphers(t_parms parms);
void	free_philosophers(t_philo **philosphers);

/* Runtime functions */
void	*start_routine();
int		ft_atoi(const char *str);

/* Test functions*/
void	print_parms(t_parms parms);
void	print_philo_ids(t_philo **philosophers);

#endif