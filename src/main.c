/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 13:21:11 by pguranda          #+#    #+#             */
/*   Updated: 2022/10/31 13:52:42 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	*routine(void* philo_data)
{
	int				number;
	pthread_mutex_t	mutex;
	void			*res = NULL;

	number = 1;
	mutex = ((t_ph_meta*)philo_data)->mutex;
	pthread_mutex_lock(&mutex);
	number++;
	printf("\n%d\n", number);
	pthread_mutex_unlock(&mutex);
	return res;
}


int	input_parsing(int argc, char **argv, t_ph_meta *philo_data)
{
	int		i;

	i = 1;
	if (argc < 5)
		return (EXIT_FAILURE);
	if (argc == 6)
		philo_data->with_option = TRUE;
	else
		philo_data->with_option = FALSE;
	//check that argvs are not nulls
	if (check_argv(philo_data, argv) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	philo_data->num_philo = atoi(argv[1]);
	philo_data ->time_die = atoi(argv[2]);
	philo_data ->time_sleep = atoi(argv[3]);
	philo_data ->time_eat = atoi(argv[4]);
	if (philo_data -> with_option == TRUE)
		philo_data->num_meals = atoi(argv[5]);
	return (EXIT_SUCCESS);
}

int main(int argc , char **argv)
{

	pthread_t			*philosophers;
	t_ph_meta			philo_data; 
	int					i;

	i = 0;
	if (input_parsing(argc, argv, &philo_data) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	// 
	philosophers = malloc(sizeof(pthread_t)*atoi(argv[1]));
	if (philosophers == NULL)
		return (1);
	if (pthread_mutex_init(&philo_data.mutex, NULL) != 0)
		return (1);
	// printf("1");
	create_threads(&philo_data, philosophers);
	if (pthread_mutex_destroy(&philo_data.mutex) != 0)
		return (1);
	free(philosophers);
	philosophers = NULL;
	return (0); 
}