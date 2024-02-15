/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiacovel <tiacovel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 14:04:15 by tiacovel          #+#    #+#             */
/*   Updated: 2024/02/15 10:28:47 by tiacovel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static t_philo	*create_philosopher(int	id, t_parms parms)
{
	t_philo	*philo;

	philo = (t_philo *)malloc(sizeof(t_philo));
	if (!philo)
		return (NULL);
	philo->id = id;
	philo->is_alive = true;
	philo->meals_counter = parms.meals_counter;
	philo->last_eat_time = 0;
	return (philo);
}

t_philo	**init_philosphers(t_parms parms)
{
	t_philo	**philosophers;
	int		i;

	philosophers = (t_philo **)malloc((parms.phils_nbr + 1) * sizeof(t_philo *));
	if (!philosophers)
		return (NULL);
	i = 0;
	while (i < parms.phils_nbr)
	{
		philosophers[i] = create_philosopher(i, parms);
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
	int	i;

	i = 0;
	while (philosphers[i] != NULL)
	{
		free(philosphers[i]);
		i++;
	}
	free(philosphers);
}
