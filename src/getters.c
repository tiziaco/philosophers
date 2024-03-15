/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiacovel <tiacovel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 11:27:45 by tiacovel          #+#    #+#             */
/*   Updated: 2024/03/15 14:01:06 by tiacovel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

bool	is_full(t_philo *philo)
{
	bool	res;

	mutex_handler(&philo->philo_mutex, LOCK);
	res = philo->is_full;
	mutex_handler(&philo->philo_mutex, UNLOCK);
	return (res);
}
