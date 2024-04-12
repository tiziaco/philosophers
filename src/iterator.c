/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiacovel <tiacovel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 16:46:50 by tiacovel          #+#    #+#             */
/*   Updated: 2024/04/12 13:26:45 by tiacovel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	*one_philo_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	wait_all_threads(philo->data);
	set_last_meal_time(philo);
	increase_thread_counter(philo->data);
	print_status(TAKE_FIRST_FORK, philo);
	while (!sim_is_running(philo->data))
		philo_sleep(philo);
	return (NULL);
}

void	*dinner_routine(void *arg)
{
	t_philo		*philo;

	philo = (t_philo *)arg;
	wait_all_threads(philo->data);
	set_last_meal_time(philo);
	increase_thread_counter(philo->data);
	de_synchronize_philos(philo);
	while (!sim_is_running(philo->data))
	{
		if (sim_is_running(philo->data))
			break ; // NOT OK: i have to check if each philosopher ate at least N times
		eat(philo);
		philo_sleep(philo);
		think(philo, false);
	}
	printf("Exiting philo nbr. %d\n", philo->id);
	set_simulation_ended(philo->data);
	return (NULL);
}

void	start_dinner_simulation(t_data *data)
{
	int		i;

	i = -1;
	if (data->parms.max_meals == 0)
		return ;
	else if (data->parms.phils_nbr == 1)
		thread_handler(&(data->philos[0]->thread_id), one_philo_routine,
			data->philos[0], CREATE);
	else
		while (++i < data->parms.phils_nbr)
			thread_handler(&(data->philos[i]->thread_id), dinner_routine,
				data->philos[i], CREATE);
	thread_handler(&data->monitor, table_manager, data, CREATE);
	gettimeofday(&data->start_time, NULL);
	set_all_threads_ready(data);
	i = -1;
	while (++i < data->parms.phils_nbr)
		thread_handler(&(data->philos[i]->thread_id), NULL, NULL, JOIN);
	// set_simulation_ended(data);
	thread_handler(&data->monitor, NULL, NULL, JOIN);
}
