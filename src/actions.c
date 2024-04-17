/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiacovel <tiacovel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 12:06:37 by tiacovel          #+#    #+#             */
/*   Updated: 2024/04/17 18:04:23 by tiacovel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	assign_forks(t_philo *philo, t_fork **forks, int philo_position)
{
	int	philo_nbr;

	philo_nbr = philo->data->parms.phils_nbr;
	philo->left_fork = forks[(philo_position + 1) % philo_nbr];
	philo->right_fork = forks[philo_position];
	if (philo->id % 2 == 0)
	{
		philo->left_fork = forks[philo_position];
		philo->right_fork = forks[(philo_position + 1) % philo_nbr];
	}
}

void	think(t_philo *philo, bool pre_simulation)
{
	long	t_eat;
	long	t_die;
	long	t_think;
	t_time	current;
	
	if (!pre_simulation)
		print_status(THINKING, philo);
	if (philo->data->parms.phils_nbr % 2 == 0)
		return ;
	mutex_handler(&philo->philo_mutex, LOCK);
	gettimeofday(&current, NULL);
	t_eat = philo->data->parms.time_to_eat;
	t_die = philo->data->parms.time_to_die;
	t_think = (t_die 
			- get_elapsed_time(philo->last_eat_time, current, MICROSECONDS)
			- t_eat) / 2;
	t_think = (t_eat * 2) - philo->data->parms.time_to_sleep;;
	if (t_think < 0)
		t_think = 0;
	if (t_think == 0)
		t_think = 1;
	if (t_think > 600)
		t_think = 200;
	mutex_handler(&philo->philo_mutex, UNLOCK);
	precise_usleep(t_think);
}

void	eat(t_philo *philo)
{
	mutex_handler(&philo->left_fork->fork_mutex, LOCK);
	print_status(TAKE_FIRST_FORK, philo);
	mutex_handler(&philo->right_fork->fork_mutex, LOCK);
	print_status(TAKE_SECOND_FORK, philo);
	set_last_meal_time(philo);
	print_status(EATING, philo);
	precise_usleep(philo->data->parms.time_to_eat);
	// if (!sim_is_running(philo->data))
	// 	increase_meals_counter(philo);
	increase_meals_counter(philo);
	mutex_handler(&philo->left_fork->fork_mutex, UNLOCK);
	mutex_handler(&philo->right_fork->fork_mutex, UNLOCK);
}

void	philo_sleep(t_philo *philo)
{
	print_status(SLEEPING, philo);
	precise_usleep(philo->data->parms.time_to_sleep);
}
