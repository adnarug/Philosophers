/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_threads.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 13:02:08 by pguranda          #+#    #+#             */
/*   Updated: 2022/10/31 13:43:52 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

static void	*routine (void *philo)
{
	void	*result;
	t_ph_meta	*phil;
	int		i;

	i = 0;
	phil = (t_ph_meta*)philo;
	result = NULL;
	printf("\n%d: death value: %d\n", phil->num_philo, phil->time_die);
	return result;
}

int	create_threads(t_ph_meta *philo, pthread_t *philosophers)
{
	int		i;
	int		*num;

	i = 0;
	printf("cheeky check");
	while (i < philo->num_philo)
	{
		num = malloc(sizeof(int));
		num = &i;
		if (pthread_create(philosophers + i, NULL, &routine, philo) != 0)
			return (EXIT_FAILURE);
		philo->time_die++;
		i++;
	}
	i = 0;
	while (i < philo->num_philo)
	{
		if (pthread_join(*(philosophers + i), NULL) != 0)
			return (EXIT_FAILURE);
		i++;
	}
	return (EXIT_SUCCESS);
}