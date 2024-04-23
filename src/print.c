/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiacovel <tiacovel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 17:38:42 by tiacovel          #+#    #+#             */
/*   Updated: 2024/04/23 15:41:07 by tiacovel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	print_parms(t_parms parms)
{
	printf("Philosophers Number: %d\n", parms.phils_nbr);
	printf("Time to Die: %d\n", parms.time_to_die);
	printf("Time to Eat: %d\n", parms.time_to_eat);
	printf("Time to Sleep: %d\n", parms.time_to_sleep);
	printf("Is Valid: %d\n", parms.is_valid);
}

void	print_philo_ids(t_philo **philosophers)
{
	int	i;

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
	mutex_handler(&philo->data->write_mutex, LOCK);
	if ((status == TAKE_FIRST_FORK || status == TAKE_SECOND_FORK)
		&& sim_is_running(philo->data))
		printf("%lld %d has taken a fork\n", get_elapsed_time(philo), philo->id);
	else if (status == EATING && sim_is_running(philo->data))
		printf("%lld %d is eating\n", get_elapsed_time(philo), philo->id);
	else if (status == SLEEPING && sim_is_running(philo->data))
		printf("%lld %d is sleeping\n", get_elapsed_time(philo), philo->id);
	else if (status == THINKING && sim_is_running(philo->data))
		printf("%lld %d is thinking\n", get_elapsed_time(philo), philo->id);
	else if (status == DIED)
		printf("%lld %d died\n", get_elapsed_time(philo), philo->id);
	mutex_handler(&philo->data->write_mutex, UNLOCK);
}
