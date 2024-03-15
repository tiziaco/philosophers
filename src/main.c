/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiacovel <tiacovel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 11:49:16 by tiacovel          #+#    #+#             */
/*   Updated: 2024/03/15 14:30:43 by tiacovel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	main(int argc, char **argv)
{
	t_data	*data;

	if (argc < 5)
		return (0);
	data = init_data(argc, argv);
	if (!data)
	{
		//free_data(data);
		return(EXIT_FAILURE);
	}
	print_parms(data->parms);
	print_philo_ids(data->philos);
	free_data(data);
	return (EXIT_SUCCESS);
}
