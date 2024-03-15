/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiacovel <tiacovel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 14:04:15 by tiacovel          #+#    #+#             */
/*   Updated: 2024/03/15 14:00:32 by tiacovel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static t_philo	*create_philosopher(int	id, t_data *data)
{
	t_philo	*philo;

	philo = (t_philo *)malloc(sizeof(t_philo));
	if (!philo)
		return (NULL);
	philo->id = id;
	philo->is_alive = true;
	philo->meals_counter = data->parms.meals_counter;
	philo->last_eat_time = 0;
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
