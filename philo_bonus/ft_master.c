/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_master.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarzi-c <fgarzi-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 20:20:23 by fgarzi-c          #+#    #+#             */
/*   Updated: 2023/04/28 02:52:32 by fgarzi-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	ft_check_time(t_philo *philo)
{
	struct timeval	interval;
	int				time_diff;

	gettimeofday(&interval, NULL);
	time_diff = ft_calculate_time(&philo->time, &interval);
	if (time_diff > philo->die_time)
		exit(3);
}

void	ft_master(t_philo *philo)
{
	usleep(1000);
	while (1)
	{
		ft_check_time(philo);
		usleep(200);
	}
}
