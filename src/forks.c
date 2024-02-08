/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiacovel <tiacovel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 11:34:41 by tiacovel          #+#    #+#             */
/*   Updated: 2024/02/08 12:01:54 by tiacovel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

pthread_mutex_t	**init_forks(int philo_nbr)
{
	pthread_mutex_t	**forks;
	int				i;

	forks = malloc((philo_nbr + 1) * sizeof(pthread_mutex_t *));
	if (!forks)
		return (NULL);
	i = 0;
	while (i < philo_nbr)
	{
		forks[i] = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
		if (!forks[i])
		{
			free_forks(forks);
			return (NULL);
		}
		pthread_mutex_init(forks[i], NULL);
		i++;
	}
	forks[i] = NULL;
	return (forks);
}

void	free_forks(pthread_mutex_t **forks)
{
	int	i;

	i = 0;
	while (forks[i] != NULL)
	{
		pthread_mutex_destroy(forks[i]);
		free(forks[i]);
		i++;
	}
	free(forks);
}
