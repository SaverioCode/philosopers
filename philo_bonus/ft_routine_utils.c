/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_routine_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarzi-c <fgarzi-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 18:11:12 by fgarzi-c          #+#    #+#             */
/*   Updated: 2023/04/28 02:52:43 by fgarzi-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_check_max_eat(t_philo *philo, int count)
{
	if (count == philo->max_eat)
	{
		philo->eat_limit = 1;
		exit(2);
	}
}

int	ft_calculate_time(struct timeval *time, struct timeval *interval)
{
	int					diff;
	unsigned long long	time_1;
	unsigned long long	time_2;

	time_1 = (time->tv_sec * 1000) + (time->tv_usec / 1000);
	time_2 = (interval->tv_sec * 1000) + (interval->tv_usec / 1000);
	diff = time_2 - time_1;
	return (diff);
}

void	ft_usleep(int time)
{
	struct timeval	start;
	struct timeval	interval;

	gettimeofday(&start, NULL);
	while (1)
	{
		usleep(200);
		gettimeofday(&interval, NULL);
		if (time == ft_calculate_time(&start, &interval))
			break ;
	}
}
