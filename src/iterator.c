/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiacovel <tiacovel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 16:46:50 by tiacovel          #+#    #+#             */
/*   Updated: 2024/02/07 17:38:50 by tiacovel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	*start_routine()
{
	t_time	start_time;
	t_time	cur_time;
	int		i;
	
	i = 0;
	gettimeofday(&start_time, 0);
	while (i < 100)
	{
		gettimeofday(&cur_time, 0);
		printf("%d\n", elapsed_time(start_time, cur_time));
		usleep(2000);
		i++;
	}
	return (NULL);
}