/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiacovel <tiacovel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 11:52:25 by tiacovel          #+#    #+#             */
/*   Updated: 2024/04/23 18:53:04 by tiacovel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

long long	get_elapsed_time(t_philo *philo)
{
	return (get_time_ms() 
		- (philo->data->start_time + philo->data->time_delta));
}

long long	get_time_ms(void)
{
	t_time	cur_time;

	gettimeofday(&cur_time, NULL);
	return ((cur_time.tv_sec * 1000) + (cur_time.tv_usec / 1000));
}

void	precise_usleep(long long msec, t_data *data)
{
	long long	wait_time;

	wait_time = get_time_ms() + msec;
	while (get_time_ms() < wait_time)
	{
		if (!sim_is_running(data))
			break ;
		usleep(200);
	}
}
