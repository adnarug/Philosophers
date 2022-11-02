/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 16:21:02 by pguranda          #+#    #+#             */
/*   Updated: 2022/11/02 14:50:41 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philosophers.h"

int	get_time(void)
{
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	return ((current_time.tv_sec * 1000) + (current_time.tv_usec / 1000));
}

unsigned long	end_time()
{
	struct timeval tv;
	gettimeofday(&tv, NULL);
	return((tv.tv_sec * 1000) - (tv.tv_usec / 1000));
}

void	mili_sleep(int i)
{
	usleep(i*1000);
}