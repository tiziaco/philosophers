/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiacovel <tiacovel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 10:38:02 by tiacovel          #+#    #+#             */
/*   Updated: 2024/03/19 15:41:35 by tiacovel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static void	handle_mutex_error(int status, t_action action)
{
	if (0 == status)
		return ;
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

static void	handle_thread_error(int status, t_action action)
{
	if (0 == status)
		return ;
	if (EAGAIN == status)
		error_exit("No resources to create another thread");
	else if (EPERM == status)
		error_exit("The caller does not have appropriate permission\n");
	else if (EINVAL == status && CREATE == action)
		error_exit("The value specified by attr is invalid.");
	else if (EINVAL == status && (JOIN == action || DETACH == action))
		error_exit("The value specified by thread is not joinable\n");
	else if (ESRCH == status)
		error_exit("No thread could be found corresponding to that"
			"specified by the given thread ID, thread.");
	else if (EDEADLK == status)
		error_exit("A deadlock was detected or the value of"
			"thread specifies the calling thread.");
}

void	thread_handler(pthread_t *thread, void *(*foo)(void *),
		void *data, t_action action)
{
	if (CREATE == action)
		handle_thread_error(pthread_create(thread, NULL, foo, data), action);
	else if (JOIN == action)
		handle_thread_error(pthread_join(*thread, NULL), action);
	else if (DETACH == action)
		handle_thread_error(pthread_detach(*thread), action);
	else
		error_exit("Wrong action for thread_handle:"
			" use <CREATE> <JOIN> <DETACH>");
}
