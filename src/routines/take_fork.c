/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_fork.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 15:31:55 by pguranda          #+#    #+#             */
/*   Updated: 2022/11/04 17:17:33 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philosophers.h"

int take_fork(t_philo	*philo)
{
	// philo->l_fork->state = FREE;
	// philo->r_fork->state = FREE;
	int		i;


	i = 0;
	// pthread_mutex_init(&mutex, NULL);
	// pthread_mutex_lock(&mutex);

	philo->curr_time = get_time();
	// printf("CUR: %d START: %d\n", philo->curr_time, philo->start_time);
	if (philo->id != 0)
	{
		// if (philo->l_fork->state == FREE && philo->r_fork->state == FREE)
		// {
			pthread_mutex_lock(philo->r_fork->mutex);
			printf("%d %d has taken a fork\n", philo->curr_time - philo->start_time, philo->id);
			philo->r_fork->state = TAKEN;
			pthread_mutex_lock(philo->r_fork->mutex);
			printf("%d %d has taken a fork\n", philo->curr_time - philo->start_time, philo->id);
			philo->r_fork->state = TAKEN;
		// }
		// usleep(500);
		// mili_sleep(philo->meta->time_eat);
	}
	// if (philo->id == 0)
	// 	usleep(10000);
	// pthread_mutex_unlock(&mutex);
	return (EXIT_SUCCESS);
}

int put_fork(t_philo	*philo)
{
	// philo->l_fork->state = FREE;
	// philo->r_fork->state = FREE;
	int		i;


	i = 0;
	// pthread_mutex_init(&mutex, NULL);
	// pthread_mutex_lock(&mutex);

	philo->curr_time = get_time();
	// printf("CUR: %d START: %d\n", philo->curr_time, philo->start_time);
	if (philo->id != 0)
	{
		// if (philo->l_fork->state == TAKEN && philo->r_fork->state == TAKEN)
		// {
			pthread_mutex_unlock(philo->r_fork->mutex);
			// printf("%d %d has put down a fork\n", philo->curr_time - philo->start_time, philo->id);
			philo->r_fork->state = FREE;
			pthread_mutex_unlock(philo->r_fork->mutex);
			// printf("%d %d has put down a fork\n", philo->curr_time - philo->start_time, philo->id);
			philo->r_fork->state = FREE;
		// }
		// usleep(500);
		// mili_sleep(philo->meta->time_eat);
	}
	// if (philo->id == 0)
	// 	usleep(10000);
	// pthread_mutex_unlock(&mutex);
	return (EXIT_SUCCESS);
}