/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiacovel <tiacovel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 16:46:50 by tiacovel          #+#    #+#             */
/*   Updated: 2024/04/19 14:56:46 by tiacovel         ###   ########.fr       */
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
	while (sim_is_running(philo->data))
		philo_sleep(philo);
	return (NULL);
}

void	*dinner_routine(void *arg)
{
	t_philo		*philo;

	philo = (t_philo *)arg;
	wait_all_threads(philo->data);
	increase_thread_counter(philo->data);
	mutex_handler(&philo->philo_mutex, LOCK);
	philo->last_eat_time = philo->data->start_time;
	mutex_handler(&philo->philo_mutex, UNLOCK);
	de_synchronize_philos(philo);
	while (sim_is_running(philo->data) == true)
	{
		eat(philo);
		philo_sleep(philo);
		think(philo, false);
	}
	return (NULL);
}

void	start_dinner_simulation(t_data *data)
{
	int		i;

	i = -1;
	if (data->parms.max_meals == 0 || data->parms.phils_nbr == 0)
		return ;
	if (data->parms.phils_nbr == 1)
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
	set_simulation_ended(data);
	thread_handler(&data->monitor, NULL, NULL, JOIN);
}
