/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiacovel <tiacovel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 11:34:41 by tiacovel          #+#    #+#             */
/*   Updated: 2024/02/15 10:41:18 by tiacovel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

t_mutex	**init_forks(int philo_nbr)
{
	t_mutex	**forks;
	int		i;

	forks = malloc((philo_nbr + 1) * sizeof(t_mutex *));
	if (!forks)
		return (NULL);
	i = 0;
	while (i < philo_nbr)
	{
		forks[i] = (t_mutex *)malloc(sizeof(t_mutex));
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

void	free_forks(t_mutex **forks)
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
