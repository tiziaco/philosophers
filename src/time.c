/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiacovel <tiacovel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 11:52:25 by tiacovel          #+#    #+#             */
/*   Updated: 2024/02/15 10:42:43 by tiacovel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	elapsed_time_ms(t_time start_time, t_time end_time)
{
	long long	t1;
	long long	t2;

	t1 = (start_time.tv_sec * 1000) + (start_time.tv_usec / 1000);
	t2 = (end_time.tv_sec * 1000) + (end_time.tv_usec / 1000);
	return (t2 - t1);
}

long	get_elapsed_time_us(t_time start, t_time end)
{
	return (end.tv_sec - start.tv_sec) * 1000000L + (end.tv_usec - start.tv_usec);
}

void precise_usleep(long usec)
{
	t_time start, current;
	long elapsed;

	gettimeofday(&start, NULL);
	gettimeofday(&current, NULL);
	elapsed = get_elapsed_time_us(start, current);
	while (elapsed < usec)
	{
		gettimeofday(&current, NULL);
		elapsed = get_elapsed_time_us(start, current);
		if (elapsed < usec)
			usleep(50);
	}
}
