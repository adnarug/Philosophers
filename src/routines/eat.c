/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 16:54:14 by pguranda          #+#    #+#             */
/*   Updated: 2022/11/04 17:03:49 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philosophers.h"

int eat(t_philo *philo)
{
	printf("%d %d is eating\n", philo->curr_time - philo->start_time, philo->id);
	my_sleep(philo->meta->time_eat);
	put_fork(philo);
	return (EXIT_SUCCESS);
}