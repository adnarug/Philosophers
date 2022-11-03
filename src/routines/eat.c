/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 15:31:55 by pguranda          #+#    #+#             */
/*   Updated: 2022/11/03 16:34:57 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philosophers.h"

void	my_sleep(int ms)
{
	int	curtime;

	curtime = get_time();
	while ((get_time() - curtime) < ms)
		usleep(100);
}

int eating(t_philo	*philo)
{
	// philo->l_fork->state = FREE;
	// philo->r_fork->state = FREE;
	int		i;


	i = 0;
	// pthread_mutex_init(&mutex, NULL);
	// pthread_mutex_lock(&mutex);
	if (philo->l_fork->state == FREE && philo->r_fork->state == FREE)
		printf("%d %d has taken a fork\n", get_time(), philo->id);
	// usleep(500);
	mili_sleep(philo->meta->time_eat);
	printf("%d %d has put down a fork\n", get_time(), philo->id);
	// pthread_mutex_unlock(&mutex);
	return (EXIT_SUCCESS);
}