/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiacovel <tiacovel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 16:46:50 by tiacovel          #+#    #+#             */
/*   Updated: 2024/03/15 18:30:50 by tiacovel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

/* TEST precise sleep */
/* void	*start_routine()
{
	t_time	start_time;
	t_time	cur_time;
	int		i;
	
	i = 0;
	gettimeofday(&start_time, 0);
	while (i < 4000)
	{
		gettimeofday(&cur_time, 0);
		printf("%lld\n", get_elapsed_time(start_time, cur_time, MILLISECONDS));
		precise_usleep(4000);
		i++;
	}
	//printf("	Total elapsed time: %d [ms]\n", elapsed_time_ms(start_time, cur_time));
	return (NULL);
} */

void	*dinner_routine(void *arg)
{
	t_philo		*philo;

	philo = (t_philo *)arg;
	wait_all_threads(philo->data);
	set_last_meal_time(philo);
	increase_thread_counter(philo->data);
	de_synchronize_philos(philo);
	while (!sim_is_running(philo->data))
	{
		if (philo_is_full(philo))
			break ;
		eat(philo);
		philo_sleep(philo);
		think(philo, false);
	}
	return (NULL);
}
