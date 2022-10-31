/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 15:31:55 by pguranda          #+#    #+#             */
/*   Updated: 2022/10/31 17:34:10 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philosophers.h"

int eating(t_philo	*philo, t_ph_meta *meta)
{
	if (philo->l_fork->state == FREE && philo->r_fork->state == FREE)
		printf("%lus %d has taken a fork", start_time, philo->id);
	usleep(philo->meta->time_eat);
	printf("%d has taken a fork", philo->id);
}