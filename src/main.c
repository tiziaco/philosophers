/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiacovel <tiacovel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 11:49:16 by tiacovel          #+#    #+#             */
/*   Updated: 2024/04/19 14:51:20 by tiacovel         ###   ########.fr       */
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
		free_data(data);
		return (EXIT_FAILURE);
	}
	start_dinner_simulation(data);
	free_data(data);
	return (EXIT_SUCCESS);
}
