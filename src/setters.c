/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiacovel <tiacovel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 16:31:16 by tiacovel          #+#    #+#             */
/*   Updated: 2024/04/18 14:05:36 by tiacovel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	set_last_meal_time(t_philo *philo)
{
	mutex_handler(&philo->philo_mutex, LOCK);
	gettimeofday(&philo->last_eat_time, NULL);
	mutex_handler(&philo->philo_mutex, UNLOCK);
}

void	set_full(t_philo *philo)
{
	mutex_handler(&philo->philo_mutex, LOCK);
	philo->is_full = true;
	mutex_handler(&philo->philo_mutex, UNLOCK);
}

void	increase_meals_counter(t_philo *philo)
{
	mutex_handler(&philo->philo_mutex, LOCK);
	philo->meals_counter++;
	mutex_handler(&philo->philo_mutex, UNLOCK);
}

void	set_simulation_ended(t_data *data)
{
	mutex_handler(&data->table_mutex, LOCK);
	// printf("Yoooooooooooooo\n");
	data->sim_is_running = false;
	mutex_handler(&data->table_mutex, UNLOCK);
}

void	increase_thread_counter(t_data *data)
{
	mutex_handler(&data->table_mutex, LOCK);
	data->threads_counter++;
	mutex_handler(&data->table_mutex, UNLOCK);
}

void	set_all_threads_ready(t_data *data)
{
	mutex_handler(&data->table_mutex, LOCK);
	data->all_threads_ready = true;
	data->sim_is_running = true;
	mutex_handler(&data->table_mutex, UNLOCK);
}
