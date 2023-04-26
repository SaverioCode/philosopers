/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_master.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarzi-c <fgarzi-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 20:20:23 by fgarzi-c          #+#    #+#             */
/*   Updated: 2023/04/26 22:32:34 by fgarzi-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_check_eating(t_philo *philo)
{
	int	i;
	int	c;

	c = 0;
	i = 0;
	while (i < philo->philo_num)
	{
		if (philo->eat_limit[i] == 1)
			c++;
		i++;
	}
	if (c == philo->philo_num)
	{
		pthread_mutex_lock(&philo->data.death_mutex);
		philo->data.death = 0;
		pthread_mutex_unlock(&philo->data.death_mutex);
		return (0);
	}
	return (1);
}

int	ft_check_time(t_philo *philo, int id)
{
	struct timeval	interval;
	int				time_diff;
	int				time_death;

	gettimeofday(&interval, NULL);
	time_diff = ft_calculate_time(&philo->time[id], &interval);
	if (!philo->data.death)
		return (0);
	if (time_diff > philo->die_time)
	{
		pthread_mutex_lock(&philo->data.death_mutex);
		philo->data.death = 0;
		pthread_mutex_unlock(&philo->data.death_mutex);
		time_death = ft_calculate_time(&philo->master_time, &interval);
		printf("%d %d died\n", time_death, id + 1);
		return (0);
	}
	return (1);
}

void	ft_master(t_philo *philo)
{
	int	i;

	gettimeofday(&philo->master_time, NULL);
	usleep(1000);
	while (philo->data.death)
	{
		i = 0;
		while (i < philo->philo_num)
		{
			if (!philo->eat_limit[i])
			{
				if (!ft_check_time(philo, i) || !ft_check_eating(philo))
				{
					philo->master_value = 0;
					return ;
				}
			}
			i++;
			usleep(20);
		}
	}
	philo->master_value = 0;
}
