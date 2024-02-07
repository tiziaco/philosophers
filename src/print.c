/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiacovel <tiacovel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 17:38:42 by tiacovel          #+#    #+#             */
/*   Updated: 2024/02/07 17:47:56 by tiacovel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	print_parms(t_parms parms)
{
	printf("Philosophers Number: %d\n", parms.phils_nbr);
	printf("Time to Die: %d\n", parms.time_to_die);
	printf("Time to Eat: %d\n", parms.time_to_eat);
	printf("Time to Sleep: %d\n", parms.time_to_sleep);
	printf("Is Valid: %s\n", parms.is_valid ? "true" : "false");
}

void	print_philo_ids(t_philo **philosophers)
{
	int i;

	i = 0;
	while (philosophers[i] != NULL)
	{
		printf("Philosopher's ID: %d => READY\n", philosophers[i]->id);
		i++;
	}
}
