/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 13:21:55 by pguranda          #+#    #+#             */
/*   Updated: 2022/10/30 14:31:04 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>//to be deleted
#include <string.h>//to be deleted
#include <pthread.h>

typedef struct s_ph 
{
	int					num_philo;
	pthread_mutex_t		mutex;
} t_ph;

#endif