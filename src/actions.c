/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiacovel <tiacovel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 12:06:37 by tiacovel          #+#    #+#             */
/*   Updated: 2024/04/23 18:37:31 by tiacovel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	think(t_philo *philo, bool pre_simulation)
{
	int			t_eat;
	int			t_die;
	int			t_think;
	long long	current;

	mutex_handler(&philo->philo_mutex, LOCK);
	current = get_time_ms();
	t_eat = philo->data->parms.time_to_eat;
	t_die = philo->data->parms.time_to_die;
	t_think = (t_die 
			- (current - philo->last_eat_time)
			- t_eat) / 2;
	mutex_handler(&philo->philo_mutex, UNLOCK);
	if (t_think < 0)
		t_think = 0;
	if (t_think == 0 && pre_simulation == true)
		t_think = 1;
	if (t_think > 200)
		t_think = 200;
	if (!pre_simulation)
		print_status(THINKING, philo);
	precise_usleep(t_think, philo->data);
}

/* void	think(t_philo *philo, bool pre_simulation)
{
	long	t_eat;
	long	t_sleep;
	long	t_think;
	
	if (!pre_simulation)
		print_status(THINKING, philo);
	mutex_handler(&philo->philo_mutex, LOCK);
	t_eat = philo->data->parms.time_to_eat;
	t_sleep = philo->data->parms.time_to_sleep;
	t_think = (t_eat * 2) - t_sleep;
	if (t_think < 0)
		t_think = 0;
	mutex_handler(&philo->philo_mutex, UNLOCK);
	precise_usleep(t_think*0.42, philo->data);
} */

void	eat(t_philo *philo)
{
	mutex_handler(&philo->left_fork->fork_mutex, LOCK);
	print_status(TAKE_FIRST_FORK, philo);
	mutex_handler(&philo->right_fork->fork_mutex, LOCK);
	print_status(TAKE_SECOND_FORK, philo);
	set_last_meal_time(philo);
	print_status(EATING, philo);
	precise_usleep(philo->data->parms.time_to_eat, philo->data);
	increase_meals_counter(philo);
	mutex_handler(&philo->right_fork->fork_mutex, UNLOCK);
	mutex_handler(&philo->left_fork->fork_mutex, UNLOCK);
}

void	philo_sleep(t_philo *philo)
{
	print_status(SLEEPING, philo);
	precise_usleep(philo->data->parms.time_to_sleep, philo->data);
}
