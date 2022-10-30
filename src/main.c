/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 13:21:11 by pguranda          #+#    #+#             */
/*   Updated: 2022/10/30 14:36:12 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	*routine(void* philo_data)
{
	int				number;
	pthread_mutex_t	mutex;
	void			*res = NULL;

	mutex = (t_ph*)philo_data->mutex;
	number = 10;
	pthread_mutex_lock(&(t_ph)philo_data->mutex);
	
	printf("%s", (char*)args);
	return res;
}


void	input_parsing(char **argv, t_ph *philo_data)
{
	philo_data -> num_philo = atoi(argv[1]);//to use my atoi
	return ;
}

int main(int argc , char **argv)
{
	pthread_t		philosophers;
	t_ph			philo_data;
	int				i;

	i = 0;
	if (argc > 5 || argc < 3 )
		return (1);
	if (pthread_mutex_init(&philo_data.mutex, NULL) != 0)
		return (1);
	input_parsing(argv, &philo_data);
	while (i < argc)
	{
		pthread_create(&philosophers, NULL, &routine, &philo_data); 
		i++;
	}
	i = 0;
	while (i < argc)
	{
		pthread_join(philosophers, NULL);
		i++;
	}
	if (pthread_mutex_destroy(&mutex) != 0)
		return (1);
	return (0); 
}