/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_threads.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 13:02:08 by pguranda          #+#    #+#             */
/*   Updated: 2022/11/06 13:06:27 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"


// int	monitoring(t_philo	*philos)
// {
// 	while (philos->meta->died != TRUE)
		
// }

int	create_thread(t_philo *philos)
{
	int		counter;
	int		i;

	counter = 0;
	i = 0;
	// printf("id of the philo before:%d\n", philos->id);

	if (pthread_create(&philos->threads, NULL, &routine, (void *)philos) != 0)
		return (EXIT_FAILURE);
	
	return (EXIT_SUCCESS);
}