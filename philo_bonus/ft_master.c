/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_master.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarzi-c <fgarzi-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 20:20:23 by fgarzi-c          #+#    #+#             */
/*   Updated: 2023/04/24 16:10:45 by fgarzi-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_check_time(t_philo *philo, int id)
{
	struct timeval	interval;
	int				time_diff;
	int				time_death;

	gettimeofday(&interval, NULL);
	time_diff = ft_calculate_time(&philo->time[id], &interval);
	if (time_diff >= philo->die_time)
	{
		sem_wait(philo->data.death);
		time_death = ft_calculate_time(&philo->master_time, &interval);
		printf("%d %d died\n", time_death, id + 1);
		return (0);
	}
	return (1);
}

void	ft_master(t_philo *philo)
{
	int	i;

	usleep(10000);
	while (*philo->data.death)
	{
		i = 0;
		while (i < philo->philo_num)
		{
			if (!philo->eat_limit[i])
			{
				if (!ft_check_time(philo, i))
					break ;
				if (!*philo->data.death)
					break ;
			}
			i++;
		}
	}
}
