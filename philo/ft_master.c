/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_master.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarzi-c <fgarzi-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 20:20:23 by fgarzi-c          #+#    #+#             */
/*   Updated: 2023/04/20 21:48:52 by fgarzi-c         ###   ########.fr       */
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
	if (time_diff / 1000 >= philo->die_time)
	{
		pthread_mutex_lock(&philo->data.death_mutex);
		philo->data.death = 0;
		pthread_mutex_unlock(&philo->data.death_mutex);
		time_death = ft_calculate_time(&philo->master_time, &interval);
		printf("%d %d died\n", time_death / 1000, id + 1);
		return (0);
	}
	return (1);
}

void	ft_master(t_philo *philo)
{
	int	i;

	gettimeofday(&philo->master_time, NULL);
	while (ft_check_death(philo))
	{
		i = 0;
		while (i < philo->data.philo_num)
		{
			if (!ft_check_time(philo, i))
				return ;
			if (!ft_check_death(philo))
				return ;
			i++;
		}
	}
}
