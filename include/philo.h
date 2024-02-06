/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiacovel <tiacovel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 11:47:39 by tiacovel          #+#    #+#             */
/*   Updated: 2024/02/06 17:21:10 by tiacovel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdbool.h>
# include <sys/time.h>

typedef struct timeval t_time;
typedef struct s_philo
{
	int	id;
	int	time_to_sleep;
	int	time_to_think;
	int	time_to_eat;
	int	last_eat_time;
}	t_philo;

unsigned long	time_now();
int		elapsed_time(t_time start_time, t_time end_time);

void	start_routine();

#endif