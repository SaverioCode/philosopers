/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_master.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarzi-c <fgarzi-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 20:20:23 by fgarzi-c          #+#    #+#             */
/*   Updated: 2023/04/24 16:46:11 by fgarzi-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	ft_kill_them_all(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->philo_num)
	{
		kill(philo->pid[i], SIGKILL);
		i++;
	}
}

int	ft_check_time(t_philo *philo, int id)
{
	struct timeval	interval;
	int				time_diff;
	int				time_death;

	gettimeofday(&interval, NULL);
	time_diff = ft_calculate_time(&philo->time[id], &interval);
	if (time_diff >= philo->die_time)
	{
		ft_kill_them_all(philo);
		time_death = ft_calculate_time(&philo->master_time, &interval);
		printf("%d %d died\n", time_death, id + 1);
		return (0);
	}
	return (1);
}

void	ft_master(t_philo *philo)
{
	int	i;

	while (1)
	{
		i = 0;
		while (i < philo->philo_num)
		{
			if (!philo->eat_limit[i])
				if (!ft_check_time(philo, i))
					break ;
			i++;
		}
	}
}
