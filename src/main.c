/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 13:21:11 by pguranda          #+#    #+#             */
/*   Updated: 2022/11/06 17:23:44 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

/*TODO:
- protect printf
- fix the watcher - need to start all threads, then watch
- check timestamps
- routine functions are simplisting and not protected
- philo dies, if time to die is less than time to eat
- renew the timer, when they start eating
- check timing - always only hundreds
- 1 and 5 cannot start together
- check the leaks, data races*/

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


int main(int argc , char **argv)
{

	t_philo				*philos;
	t_ph_meta			philo_data;
	int					i;

	i = 0;
	philos = NULL;
	if (input_parsing(argc, argv, &philo_data) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	philos = init_philos(philos, &philo_data); 
	if (philos == NULL)
		return (EXIT_FAILURE);
	// monitor_philos(philos);
	if (start_dinner(philos) == 1)
		return (EXIT_FAILURE);
	// free(philos->threads);
	free (philos);
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
