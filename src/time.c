/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiacovel <tiacovel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 11:52:25 by tiacovel          #+#    #+#             */
/*   Updated: 2024/02/06 17:10:31 by tiacovel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	elapsed_time(t_time start_time, t_time end_time)
{
	long long	t1;
	long long	t2;

	t1 = (start_time.tv_sec * 1000) + (start_time.tv_usec / 1000);
	t2 = (end_time.tv_sec * 1000) + (end_time.tv_usec / 1000);
	return (t2 - t1);
}

unsigned long	time_now()
{
	t_time	datetime;

	gettimeofday(&datetime, 0);
	return (datetime.tv_usec/1000);
}