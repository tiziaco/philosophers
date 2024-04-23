/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sync_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiacovel <tiacovel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 18:03:34 by tiacovel          #+#    #+#             */
/*   Updated: 2024/04/23 15:40:13 by tiacovel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	wait_all_threads(t_data *data)
{
	while (!all_threads_ready(data))
		;
}

bool	all_threads_running(t_data *data)
{
	bool	res;

	res = false;
	mutex_handler(&data->table_mutex, LOCK);
	if (data->threads_counter == data->parms.phils_nbr)
		res = true;
	mutex_handler(&data->table_mutex, UNLOCK);
	return (res);
}

void	de_synchronize_philos(t_philo *philo)
{
	if (philo->id % 2)
		think(philo, true);
}
