/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiacovel <tiacovel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 12:06:37 by tiacovel          #+#    #+#             */
/*   Updated: 2024/04/12 13:02:35 by tiacovel         ###   ########.fr       */
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
	long	t_sleep;
	long	t_think;

	if (!pre_simulation)
		print_status(THINKING, philo);
	if (philo->data->parms.phils_nbr % 2 == 0)
		return ;
	t_eat = philo->data->parms.time_to_eat;
	t_sleep = philo->data->parms.time_to_sleep;
	t_think = (t_eat * 2) - t_sleep;
	if (t_think < 0)
		t_think = 0;
	precise_usleep(t_think * 0.42);
}

void	eat(t_philo *philo)
{
	mutex_handler(&philo->left_fork->fork_mutex, LOCK);
	print_status(TAKE_FIRST_FORK, philo);
	mutex_handler(&philo->right_fork->fork_mutex, LOCK);
	print_status(TAKE_SECOND_FORK, philo);
	set_last_meal_time(philo);
	
	//printf("OOOK... %d \n", philo->meals_counter);
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
