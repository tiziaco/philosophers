/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiacovel <tiacovel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 16:46:50 by tiacovel          #+#    #+#             */
/*   Updated: 2024/02/08 15:25:09 by tiacovel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	*start_routine()
{
	t_time	start_time;
	t_time	cur_time;
	int		i;
	
	i = 0;
	gettimeofday(&start_time, 0);
	while (i < 100)
	{
		gettimeofday(&cur_time, 0);
		printf("%d\n", elapsed_time(start_time, cur_time));
		usleep(2000);
		i++;
	}
	return (NULL);
}

void *philosopher(void *arg)
{
	int id;
	int left_fork = id;
	int right_fork = (id + 1); //% NUM_PHILOSOPHERS; TODO: put data(forks and philosophers) in a struct

	id = *(int *)arg;
	while (1) 
	{
		// Thinking
		printf("Philosopher %d is thinking.\n", id);
		sleep(1);

		// Pick up forks
		printf("Philosopher %d is picking up forks.\n", id);
		pthread_mutex_lock(&((*((pthread_mutex_t**)arg))[left_fork]));
		pthread_mutex_lock(&((*((pthread_mutex_t**)arg))[right_fork]));

		// Eating
		printf("Philosopher %d is eating.\n", id);
		sleep(1);

		// Put down forks
		pthread_mutex_unlock(&((*((pthread_mutex_t**)arg))[right_fork]));
		pthread_mutex_unlock(&((*((pthread_mutex_t**)arg))[left_fork]));
	}
	return NULL;
}
