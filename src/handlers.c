/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiacovel <tiacovel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 10:38:02 by tiacovel          #+#    #+#             */
/*   Updated: 2024/02/16 10:48:54 by tiacovel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static void	handle_mutex_error(int status, t_action action)
{
	if (0 == status)
		return;
	if ((action == LOCK || action == UNLOCK) && status == EINVAL)
		error_exit("The value specified by mutex is invalid");
	else if (action == INIT && status == EINVAL)
		error_exit("The value specified by attr is invalid.");
	else if (status == EDEADLK)
		error_exit("A deadlock would occur if the thread blocked \
					waiting for mutex.");
	else if (status == EPERM)
		error_exit("The current thread does not hold a lock on mutex.");
	else if (status == ENOMEM)
		error_exit("The process cannot allocate enough memory to \
					create another mutex.");
	else if (status == EBUSY)
		error_exit("Mutex is locked");
}

void	mutex_handler(t_mutex *mutex, t_action action)
{
	if (action == LOCK)
		handle_mutex_error(pthread_mutex_lock(mutex), action);
	else if (action == UNLOCK)
		handle_mutex_error(pthread_mutex_unlock(mutex), action);
	else if (action == INIT)
		handle_mutex_error(pthread_mutex_init(mutex, NULL), action);
	else if (action == DESTROY)
		handle_mutex_error(pthread_mutex_destroy(mutex), action);
	else
		error_exit("Wrong action for mutex_handle: \
			use <LOCK> <UNLOCK> <INIT> <DESTROY>");
}
