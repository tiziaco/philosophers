/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiacovel <tiacovel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 11:49:16 by tiacovel          #+#    #+#             */
/*   Updated: 2024/03/15 12:40:41 by tiacovel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

t_parms	init_parms(int argc, char **argv)
{
	t_parms	parms;
	int		i;
	int		parm;

	i = 1;
	while (i <= argc)
	{
		if (!is_num(argv[i]))
			return (INVALID_PARAMS);
		parm = ft_atoi(argv[i]);
		if (parm <= 0)
			return (INVALID_PARAMS);
	}
	parms.phils_nbr = ft_atoi(argv[1]);
	parms.time_to_die = ft_atoi(argv[2]);
	parms.time_to_eat = ft_atoi(argv[3]);
	parms.time_to_sleep = ft_atoi(argv[4]);
	parms.meals_counter = 0;
	if (argc == 6)
		parms.meals_counter = ft_atoi(argv[5]);
	return (parms);
}

int	main(int argc, char **argv)
{
	t_data	*data;

	if (argc < 5)
		return (0);
	data = init_data(argc, argv);
	if (!data)
		return(EXIT_FAILURE);
	print_parms(data->parms);
	print_philo_ids(data->philos);
	free_data(data);
	return (EXIT_SUCCESS);
}

/***** TEST MAIN ********/

/* t_parms	init_parms_test()
{
	t_parms	parms;
	parms.phils_nbr = 5;
	parms.time_to_die = 200;
	parms.time_to_eat = 200;
	parms.time_to_sleep = 200;
	parms.meals_counter = 0;
	parms.is_valid = true;
	return (parms);
} */

/* int	main(void)
{
	//pthread_t t1;
	t_data	*data;
	pthread_t		t1; 
	int		argc = 5;
	char	*argv[6] = {argv[0] = "aaa\0", argv[1] = "5", argv[2] = "200", 
		argv[3] = "100", argv[4] = "150", argv[5] = NULL};
	
	data = init_data(argc, argv);
	if (!data)
		return(EXIT_FAILURE);
	
	print_parms(data->parms);
	print_philo_ids(data->philos);
	free_data(data);
	//pthread_create(&t1, NULL, &start_routine, NULL);
	//pthread_join(t1, NULL);
	return (0);
} */
