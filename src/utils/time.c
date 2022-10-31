/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 16:21:02 by pguranda          #+#    #+#             */
/*   Updated: 2022/10/31 17:32:14 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philosophers.h"

unsigned long	start_time()
{
	struct timeval tv;
	unsigned long  start;
	gettimeofday(&tv, NULL);
	return((tv.tv_sec * 1000) - (tv.tv_usec / 1000));
}

unsigned long	end_time()
{
	struct timeval tv;
	unsigned long  start;
	gettimeofday(&tv, NULL);
	return((tv.tv_sec * 1000) - (tv.tv_usec / 1000));
}

void	mili_sleep(int i)
{
	usleep(i*1000);
}