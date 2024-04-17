/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiacovel <tiacovel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 09:21:33 by tiacovel          #+#    #+#             */
/*   Updated: 2024/04/17 15:49:09 by tiacovel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static t_parms	init_parms(int argc, char **argv)
{
	t_parms	parms;
	int		i;
	int		parm;

	i = 1;
	while (i < argc)
	{
		if (!is_num(argv[i]))
			return ((t_parms){.is_valid = false});
		parm = ft_atoi(argv[i]);
		if (parm <= 0)
			return ((t_parms){.is_valid = false});
		i++;
	}
	parms.phils_nbr = ft_atoi(argv[1]);
	parms.time_to_die = ft_atoi(argv[2]) * 1000;
	parms.time_to_eat = ft_atoi(argv[3]) * 1000;
	parms.time_to_sleep = ft_atoi(argv[4]) * 1000;
	parms.max_meals = -1;
	if (argc == 6)
		parms.max_meals = ft_atoi(argv[5]);
	parms.is_valid = true;
	return (parms);
}

t_data	*init_data(int argc, char **argv)
{
	t_data	*data;

	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
		return (NULL);
	data->threads_counter = 0;
	data->sim_is_running = false;
	data->all_threads_ready = false;
	pthread_mutex_init(&data->write_mutex, NULL);
	pthread_mutex_init(&data->table_mutex, NULL);
	data->parms = init_parms(argc, argv);
	if (!data->parms.is_valid)
		return (NULL);
	data->forks = init_forks(data->parms.phils_nbr);
	if (!data->forks)
		return (NULL);
	data->philos = init_philosphers(data);
	if (!data->philos)
		return (NULL);
	return (data);
}

void	free_data(t_data *data)
{
	free_philosophers(data->philos);
	free_forks(data->forks);
	pthread_mutex_destroy(&data->table_mutex);
	pthread_mutex_destroy(&data->write_mutex);
	free(data);
}
