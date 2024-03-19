/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiacovel <tiacovel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 17:38:42 by tiacovel          #+#    #+#             */
/*   Updated: 2024/03/19 15:44:35 by tiacovel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	print_parms(t_parms parms)
{
	printf("Philosophers Number: %d\n", parms.phils_nbr);
	printf("Time to Die: %d\n", parms.time_to_die);
	printf("Time to Eat: %d\n", parms.time_to_eat);
	printf("Time to Sleep: %d\n", parms.time_to_sleep);
	printf("Is Valid: %s\n", parms.is_valid ? "true" : "false");
}

void	print_philo_ids(t_philo **philosophers)
{
	int i;

	i = 0;
	while (philosophers[i] != NULL)
	{
		printf("Philosopher's ID: %d => READY\n", philosophers[i]->id);
		printf("	Fork left: %d\n", philosophers[i]->left_fork->id);
		printf("	Fork right: %d\n", philosophers[i]->right_fork->id);
		i++;
	}
}

void	print_status(t_philo_status status, t_philo *philo)
{
	long	elapsed;
	t_time	cur_time;

	gettimeofday(&cur_time, NULL);
	elapsed = get_elapsed_time(philo->data->start_time, cur_time, MILLISECONDS);
	if (philo_is_full(philo))
		return ;
	mutex_handler(&philo->data->write_mutex, LOCK);
	if ((status == TAKE_FIRST_FORK || status == TAKE_SECOND_FORK)
		&& !sim_is_running(philo->data))
		printf("%ld %d has taken a fork\n", elapsed, philo->id);
	else if (status == EATING && !sim_is_running(philo->data))
		printf("%ld %d is eating\n", elapsed, philo->id);
	else if (status == SLEEPING && !sim_is_running(philo->data))
		printf("%ld %d is sleeping\n", elapsed, philo->id);
	else if (status == THINKING && !sim_is_running(philo->data))
		printf("%ld %d is thinking\n", elapsed, philo->id);
	else if (status == DIED)
		printf("%ld %d died\n", elapsed, philo->id);
	mutex_handler(&philo->data->write_mutex, UNLOCK);
}
