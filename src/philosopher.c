/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiacovel <tiacovel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 14:04:15 by tiacovel          #+#    #+#             */
/*   Updated: 2024/04/23 13:35:51 by tiacovel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	assign_forks(t_philo *philo, t_fork **forks, int philo_position)
{
	int	phils_nbr;

	phils_nbr = philo->data->parms.phils_nbr;
	philo->left_fork = forks[philo_position];
	philo->right_fork = forks[(philo_position + 1) % phils_nbr];
	if (philo->id % 2)
	{
		philo->left_fork = forks[(philo_position + 1) % phils_nbr];
		philo->right_fork = forks[philo_position];
	}
}

static t_philo	*create_philosopher(int id, t_data *data)
{
	t_philo	*philo;

	philo = (t_philo *)malloc(sizeof(t_philo));
	if (!philo)
		return (NULL);
	philo->id = id + 1;
	philo->is_alive = true;
	philo->meals_counter = 0;
	philo->data = data;
	pthread_mutex_init(&philo->philo_mutex, NULL);
	return (philo);
}

t_philo	**init_philosphers(t_data *data)
{
	t_philo	**philosophers;
	int		phil_nbr;
	int		i;

	phil_nbr = data->parms.phils_nbr;
	philosophers = (t_philo **)malloc((phil_nbr + 1) * sizeof(t_philo *));
	if (!philosophers)
		return (NULL);
	i = 0;
	while (i < phil_nbr)
	{
		philosophers[i] = create_philosopher(i, data);
		if (!philosophers[i])
		{
			free_philosophers(philosophers);
			return (NULL);
		}
		assign_forks(philosophers[i], data->forks, i);
		i++;
	}
	philosophers[i] = NULL;
	return (philosophers);
}

void	free_philosophers(t_philo **philosphers)
{
	int		i;
	t_philo	*philo;

	philo = NULL;
	i = 0;
	while (philosphers[i] != NULL)
	{
		philo = philosphers[i];
		pthread_mutex_destroy(&philo->philo_mutex);
		free(philosphers[i]);
		i++;
	}
	free(philosphers);
}
