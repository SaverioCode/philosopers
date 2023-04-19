/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_routine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarzi-c <fgarzi-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 16:26:26 by fgarzi-c          #+#    #+#             */
/*   Updated: 2023/04/19 19:56:53 by fgarzi-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	ft_sleep(t_philo *philo, int id)
{
	struct timeval	interval;
	int				time_diff;

	gettimeofday(&interval, NULL);
	time_diff = ft_calculate_time(&philo->time[id], &interval);
	printf("%d %d is sleeping\n", time_diff / 1000, id + 1);
	usleep(philo->sleep_time * 1000);
}

static void	ft_think(t_philo *philo, int id)
{
	struct timeval	interval;
	int				time_diff;

	gettimeofday(&interval, NULL);
	time_diff = ft_calculate_time(&philo->time[id], &interval);
	printf("%d %d is thinking\n", time_diff / 1000, id + 1);
}

static void	ft_eat(t_philo *philo, struct timeval *time, int id)
{
	int				left_fork;
	int				time_diff;

	left_fork = id - 1;
	if (id == 0)
		left_fork = philo->data.philo_num - 1;
	pthread_mutex_lock(&philo->forks[left_fork]);
	pthread_mutex_lock(&philo->forks[id]);
	gettimeofday(time, NULL);
	time_diff = ft_calculate_time(&philo->time[id], time);
	printf("%d %d is eating\n", time_diff / 1000, id + 1);
	usleep(philo->eat_time * 1000);
	pthread_mutex_unlock(&philo->forks[left_fork]);
	pthread_mutex_unlock(&philo->forks[id]);
}

void	ft_routine(t_philo *philo)
{
	int				id;
	int				count;
	struct timeval	time;

	id = ft_get_id(philo);
	count = 0;
	gettimeofday(&philo->time[id], NULL);
	gettimeofday(&time, NULL);
	while (ft_check_death(philo))
	{
		if (!ft_check_time(philo, &time, id))
			break ;
		ft_eat(philo, &time, id);
		count++;
		ft_check_max_eat(philo, count);
		if (!ft_check_death(philo) || !ft_check_time(philo, &time, id))
			break ;
		ft_sleep(philo, id);
		if (!ft_check_death(philo) || !ft_check_time(philo, &time, id))
			break ;
		ft_think(philo, id);
	}
}
