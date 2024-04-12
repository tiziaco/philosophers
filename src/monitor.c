/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiacovel <tiacovel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 17:28:10 by tiacovel          #+#    #+#             */
/*   Updated: 2024/04/12 13:25:14 by tiacovel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

bool phil_is_dead(t_philo *philo, int time_to_die)
{
	long elapsed;
	t_time cur_time;

	if (philo_is_full(philo))
		return (false);
	gettimeofday(&cur_time, NULL);
	elapsed = get_elapsed_time(philo->last_eat_time, cur_time, MICROSECONDS);
	if (elapsed > time_to_die)
		return (true);
	return (false);
}

bool	phils_are_full(t_data *data)
{
	int		i;
	bool	full_phils;

	i = -1;
	full_phils = true;
	while (++i < data->parms.phils_nbr)
	{
		bool test = philo_is_full(data->philos[i]);
		// printf("%d : %d\n", i, test);
		if (!philo_is_full(data->philos[i]))
			full_phils = false;
		i++;
	}
	if (full_phils)
	{
		set_simulation_ended(data);
		printf("Philos ate enough\n");
	}
	return (full_phils);
}

bool	phils_are_dead(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->parms.phils_nbr && !sim_is_running(data))
	{
		if (phil_is_dead(data->philos[i], data->parms.time_to_die))
		{
			set_simulation_ended(data);
			print_status(DIED, data->philos[i]);
			return (true);
		}
		i++;
	}
	return (false);
}

void *table_manager(void *arg)
{
	int		i;
	t_data *data;

	data = (t_data *)arg;
	while (!all_threads_running(data))
		;
	// printf("Start table manager\n");
	while (1)
	{
		if (phils_are_dead(data) || phils_are_full(data))
			return (NULL);
		// usleep(1000);
	}
	printf("Exiting table manager\n");
	return (NULL);
}
