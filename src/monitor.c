/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiacovel <tiacovel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 17:28:10 by tiacovel          #+#    #+#             */
/*   Updated: 2024/04/23 18:52:08 by tiacovel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

bool	phil_is_dead(t_philo *philo)
{
	long long	cur_time;

	mutex_handler(&philo->philo_mutex, LOCK);
	cur_time = get_time_ms();
	if ((cur_time - philo->last_eat_time) > philo->data->parms.time_to_die)
	{
		mutex_handler(&philo->philo_mutex, UNLOCK);
		return (true);
	}
	mutex_handler(&philo->philo_mutex, UNLOCK);
	return (false);
}

bool	phils_are_full(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->parms.phils_nbr)
	{
		if (philo_is_full(data->philos[i]))
		{
			set_simulation_ended(data);
			return (true);
		}
	}
	return (false);
}

bool	phils_are_dead(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->parms.phils_nbr && sim_is_running(data))
	{
		if (phil_is_dead(data->philos[i]))
		{
			set_simulation_ended(data);
			print_status(DIED, data->philos[i]);
			return (true);
		}
	}
	return (false);
}

void	*table_manager(void *arg)
{
	t_data	*data;

	data = (t_data *)arg;
	while (!all_threads_ready(data))
		;
	usleep(100);
	while (1)
	{
		if (phils_are_dead(data))
			break ;
		if (phils_are_full(data))
			break ;
	}
	return (NULL);
}
