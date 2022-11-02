/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 15:31:55 by pguranda          #+#    #+#             */
/*   Updated: 2022/11/02 18:27:40 by pguranda         ###   ########.fr       */
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
	// if (philo->l_fork->state == FREE && philo->r_fork->state == FREE)
		// printf(" 1 has taken a fork\n");
	int		i;

	i = 0;
	printf("%d %d has taken a fork\n", get_time(), philo->id);
	mili_sleep(philo->meta->time_eat);
	printf("%d %d has put down a fork\n", get_time(), philo->id);
	return (EXIT_SUCCESS);
}