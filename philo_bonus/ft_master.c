/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_master.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarzi-c <fgarzi-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 20:20:23 by fgarzi-c          #+#    #+#             */
/*   Updated: 2023/04/24 22:59:52 by fgarzi-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_check_time(t_philo *philo, int id)
{
	struct timeval	interval;
	int				time_diff;
	int				time_death;

	gettimeofday(&interval, NULL);
	time_diff = ft_calculate_time(&philo->time, &interval);
	if (time_diff >= philo->die_time)
	{
		kill(philo->pid[id], SIGKILL);
		time_death = ft_calculate_time(&philo->master_time, &interval);
		printf("%d %d died\n", time_death, id + 1);
		exit (0);
	}
	return (1);
}

void	ft_master(t_philo *philo)
{
	usleep(20);
	while (1)
	{
		if (philo->eat_limit)
			break ;
		if (!ft_check_time(philo, philo->id))
			break ;
	}
}
