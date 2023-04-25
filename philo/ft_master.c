/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_master.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarzi-c <fgarzi-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 20:20:23 by fgarzi-c          #+#    #+#             */
/*   Updated: 2023/04/26 00:53:23 by fgarzi-c         ###   ########.fr       */
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
	if (time_diff > 0 && time_diff > philo->die_time)
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
	int	eat;

	gettimeofday(&philo->master_time, NULL);
	usleep(1000);
	while (philo->data.death)
	{
		i = 0;
		while (i < philo->philo_num)
		{
			eat = 1;
			if (!philo->eat_limit[i])
			{
				if (!philo->data.death || !ft_check_time(philo, i))
				{
					philo->master_value = 0;
					return ;
				}
				eat--;
			}
			if (eat == 1)
				break ;
			i++;
		}
	}
	philo->master_value = 0;
}
