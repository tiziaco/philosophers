/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiacovel <tiacovel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 11:34:41 by tiacovel          #+#    #+#             */
/*   Updated: 2024/02/16 10:29:43 by tiacovel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static t_fork	*create_fork(int id)
{
	t_fork	*fork;

	fork = (t_fork *)malloc(sizeof(t_fork));
	if (!fork)
		return (NULL);
	fork->id = id;
	pthread_mutex_init(fork->fork_mutex, NULL);
	return (fork);
}

t_fork	**init_forks(int philo_nbr)
{
	t_fork	**forks;
	int		i;

	forks = malloc((philo_nbr + 1) * sizeof(t_fork *));
	if (!forks)
		return (NULL);
	i = 0;
	while (i < philo_nbr)
	{
		forks[i] = create_fork(i);
		if (!forks[i])
		{
			free_forks(forks);
			return (NULL);
		}
		i++;
	}
	forks[i] = NULL;
	return (forks);
}

void	free_forks(t_fork **forks)
{
	int	i;

	i = 0;
	while (forks[i] != NULL)
	{
		pthread_mutex_destroy(forks[i]->fork_mutex);
		free(forks[i]);
		i++;
	}
	free(forks);
}
