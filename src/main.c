/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 13:21:11 by pguranda          #+#    #+#             */
/*   Updated: 2022/11/03 16:31:48 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"


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

int	init_philos(t_philo *philos, t_ph_meta *philo_data)
{
	int	i;
	
	i = 0;
	philos =  malloc(sizeof(t_philo) * philo_data->num_philo); //maybe we allocate only the pointers here 
	//printf("Philosopher id: %d\n", philos[3].id);
	if (create_threads(philo_data, philos) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	// while (i < philos->meta->num_philo)
	// {
	// 	pthread_join(philos->threads[i], NULL);
	// 	i++;
	// }
	return (EXIT_SUCCESS);
}

int main(int argc , char **argv)
{

	t_philo				*philos;
	t_ph_meta			philo_data;
	int					i;

	i = 0;
	philos = NULL;
	if (input_parsing(argc, argv, &philo_data) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	init_philos(philos, &philo_data);
	// free(philos->threads);
	free(philos);
	// system("leaks philosophers");
	// if (pthread_mutex_init(&philo_data.mutex, NULL) != 0)
	// 	return (1);
	// printf("1");
	// create_threads(&philo_data, &philos);
	// eating(&philos);
	// if (pthread_mutex_destroy(&philo_data.mutex) != 0)
	// 	return (1);
	return (0); 
}