/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiacovel <tiacovel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 11:49:16 by tiacovel          #+#    #+#             */
/*   Updated: 2024/02/06 12:35:40 by tiacovel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

/* int	main(int argc, char **argv)
{
	if (argc < 5)
		return (0);
	return (0);
} */

/***** TEST MAIN ********/
#include <stdio.h>
int main(void)
{
	unsigned long time;

	time = time_now();
	printf("UNIX timestamp ms: %lu\n", time);
	return (0);
}