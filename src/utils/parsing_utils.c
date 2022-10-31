/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 11:37:45 by pguranda          #+#    #+#             */
/*   Updated: 2022/10/31 13:43:52 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philosophers.h"

int check_argv(t_ph_meta	*philo_data, char **argv)
{
	int	i;

	i = 1;
	while (argv[i] != NULL)
	{
		if (philo_data->with_option == TRUE && i < 6 && argv[i] == NULL) //think better about the optional 
		{
			perror("Wrong input - check the args");
			return (EXIT_FAILURE);
		}
		if (philo_data->with_option == FALSE && i < 5 && argv[i] == NULL)
		{
			perror("Wrong input - check the args");
			return (EXIT_FAILURE);
		}
		i++;	
	}
	return (EXIT_SUCCESS);
}

void	print_struct(t_ph_meta *philo)
{
	printf("philo->num_philo :>> %d\n", philo->num_philo);
	printf("philo->die :>> %d\n", philo->time_die);
	printf("philo->eat :>> %d\n", philo->time_eat);
	printf("philo->sleep:>> %d\n", philo->time_sleep);
	if (philo->with_option == TRUE)
		printf("philo->num_meals:>> %d\n", philo->num_meals);
}