/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 13:21:11 by pguranda          #+#    #+#             */
/*   Updated: 2022/11/04 16:52:22 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

/*TODO:
- protect printf
- make a watcher
- introduce timer
- introduce other routines
- check the leaks*/
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
		philo_data->meals_limit = atoi(argv[5]);
	return (EXIT_SUCCESS);
}
/*Initialization is always done per thread = per philo*/
int	init_philos(t_philo *philos, t_ph_meta *philo_data)
{
	int	i;
	
	i = 0;
	philos =  malloc(sizeof(t_philo) * philo_data->num_philo); //maybe we allocate only the pointers here 
	while (i < philo_data->num_philo)
	{
		philos[i].meta = philo_data;
		philos[i].id = i;
		//printf("Philosopher id: %d\n", philos[3].id)
		if (init_forks_as_mutex(&philos[i]) == EXIT_FAILURE)
			return (EXIT_FAILURE);
		if (philos[i].id != 0)
			philos[i].l_fork =  philos[i - 1].r_fork;
		if (create_thread(&philos[i]) == EXIT_FAILURE)
			return (EXIT_FAILURE);
		philos[i].start_time = get_time();
		// if (philos[i].id == 3 && philos[i].r_fork->state == FREE && philos[i].l_fork->state == FREE)
		// 	printf("cheeky check\n");
		i++;
	}
	i = 0;
	while (i < philos->meta->num_philo)
	{
		pthread_join(philos[i].threads, NULL);
		i++;
	}
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
	// system("leaks philosophers");
	return (0); 
}