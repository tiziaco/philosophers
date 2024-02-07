/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiacovel <tiacovel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 11:49:16 by tiacovel          #+#    #+#             */
/*   Updated: 2024/02/07 17:51:03 by tiacovel         ###   ########.fr       */
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
	parms.nbr_must_eat = 0;
	if (argc == 6)
		parms.nbr_must_eat = ft_atoi(argv[5]);
	return (parms);
}

/* int	main(int argc, char **argv)
{
	t_philo	**philosophers;
	t_parms	parms;

	if (argc < 5)
		return (0);
	parms = init_parms(argc, argv);
	if (!parms.is_valid)
		return (PARMS_ERROR);
	philosophers = init_philosphers(parms);
	if (!parms.is_valid)
		return (ALLOCATION_ERROR);
	return (0);
} */

/***** TEST MAIN ********/

t_parms	init_parms_test()
{
	t_parms	parms;
	parms.phils_nbr = 5;
	parms.time_to_die = 200;
	parms.time_to_eat = 200;
	parms.time_to_sleep = 200;
	parms.is_valid = true;
	return (parms);
}
int main(void)
{
	//pthread_t t1;
	t_philo **philosophers;
	t_parms	parms;

	parms = init_parms_test();
	if (!parms.is_valid)
		return (PARMS_ERROR);
	philosophers = init_philosphers(parms);
	if (!parms.is_valid)
		return (ALLOCATION_ERROR);
	print_parms(parms);
	print_philo_ids(philosophers);
	free_philosophers(philosophers);
	/* pthread_create(&t1, NULL, &start_routine, NULL);
	pthread_join(t1, NULL); */
	return (0);
}