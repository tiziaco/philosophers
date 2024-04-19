/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiacovel <tiacovel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 11:52:25 by tiacovel          #+#    #+#             */
/*   Updated: 2024/04/19 14:46:24 by tiacovel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

long long	get_elapsed_time(t_time start, t_time end, t_time_unit unit)
{
	long long	t1;
	long long	t2;

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
	else
	{
		t1 = 0;
		t2 = 0;
	}
	return (t2 - t1);
}

void	precise_usleep(long usec, t_data *data)
{
	t_time	start;
	t_time	current;
	long	elapsed;

	gettimeofday(&start, NULL);
	gettimeofday(&current, NULL);
	elapsed = get_elapsed_time(start, current, MICROSECONDS);
	while (elapsed < usec)
	{
		if (!sim_is_running(data))
			break ;
		gettimeofday(&current, NULL);
		elapsed = get_elapsed_time(start, current, MICROSECONDS);
		if (elapsed < usec)
			usleep(10);
	}
}
