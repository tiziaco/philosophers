/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiacovel <tiacovel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 11:27:45 by tiacovel          #+#    #+#             */
/*   Updated: 2024/04/19 14:56:36 by tiacovel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

bool	philo_is_full(t_philo *philo)
{
	bool	res;

	mutex_handler(&philo->philo_mutex, LOCK);
	if ((philo->data->parms.max_meals > 0)
		&& (philo->meals_counter > philo->data->parms.max_meals))
		res = true;
	else
		res = false;
	mutex_handler(&philo->philo_mutex, UNLOCK);
	return (res);
}

bool	sim_is_running(t_data *data)
{
	bool	res;

	mutex_handler(&data->table_mutex, LOCK);
	res = data->sim_is_running;
	mutex_handler(&data->table_mutex, UNLOCK);
	return (res);
}

bool	all_threads_ready(t_data *data)
{
	bool	res;

	mutex_handler(&data->table_mutex, LOCK);
	res = data->all_threads_ready;
	mutex_handler(&data->table_mutex, UNLOCK);
	return (res);
}
