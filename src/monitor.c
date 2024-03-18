/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiacovel <tiacovel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 17:28:10 by tiacovel          #+#    #+#             */
/*   Updated: 2024/03/18 19:26:33 by tiacovel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

bool	phil_is_dead(t_philo *philo, int time_to_die)
{
	long	elapsed;
	t_time	cur_time;

	if (philo_is_full(philo))
		return (false);
	gettimeofday(&cur_time, NULL);
	elapsed = get_elapsed_time(philo->last_eat_time, cur_time, MICROSECONDS);
	if (elapsed > time_to_die)
		return (true);
	return (false);
}

void	*table_manager(void *arg)
{
	int		i;
	t_data	*data;

	data = (t_data *)arg;
	while (!all_threads_running(data))
		;
	while (!sim_is_running(data))
	{	
		i = -1;
		while (++i < data->parms.phils_nbr && !sim_is_running(data))
		{
			if (phil_is_dead(data->philos[i], data->parms.time_to_die))
			{
				set_simulation_ended(data);
				print_status(DIED, data->philos[i]);
			}
			i++;
		}
	}
	return (NULL);
}
