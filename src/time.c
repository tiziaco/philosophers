/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiacovel <tiacovel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 11:52:25 by tiacovel          #+#    #+#             */
/*   Updated: 2024/04/19 18:39:41 by tiacovel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

long long	get_elapsed_time(t_time start, t_time end, t_time_unit unit)
{
	long long	t1;
	long long	t2;

	t1 = 0;
	t2 = 0;
	if (unit == MILLISECONDS)
	{
		t1 = (start.tv_sec * 1000) + (start.tv_usec / 1000);
		t2 = (end.tv_sec * 1000) + (end.tv_usec / 1000);
	}
	else if (unit == MICROSECONDS)
	{
		t1 = (start.tv_sec * 1000000L) + start.tv_usec;
		t2 = (end.tv_sec * 1000000L) + end.tv_usec;
	}
	return (t2 - t1);
}

long long	get_time_ms()
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
		usleep(100);
	}
}
