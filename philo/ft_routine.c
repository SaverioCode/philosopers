/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_routine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarzi-c <fgarzi-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 16:26:26 by fgarzi-c          #+#    #+#             */
/*   Updated: 2023/04/26 00:58:00 by fgarzi-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	ft_action(t_philo *philo, int id, int time, char *str)
{
	struct timeval	interval;
	int				time_diff;

	gettimeofday(&interval, NULL);
	time_diff = ft_calculate_time(&philo->master_time, &interval);
	printf("%d %d %s\n", time_diff, id + 1, str);
	usleep(time * 999);
}

static void	take_fork(t_philo *philo, int fork, int id, struct timeval *interval)
{
	int				time_diff;

	pthread_mutex_lock(&philo->forks[fork]);
	gettimeofday(interval, NULL);
	time_diff = ft_calculate_time(&philo->master_time, interval);
	printf("%d %d has taken a fork\n", time_diff, id + 1);
}

static int	ft_eat(t_philo *philo, int id, int *forks, struct timeval *interval)
{
	int				time_diff;

	if (id % 2 != 0)
	{
		take_fork(philo, forks[1], id, interval);
		take_fork(philo, forks[0], id, interval);
	}
	else
	{
		take_fork(philo, forks[0], id, interval);
		take_fork(philo, forks[1], id, interval);
	}
	gettimeofday(&philo->time[id], NULL);
	if (!ft_check_death(philo))
		return (0);
	time_diff = ft_calculate_time(&philo->master_time, &philo->time[id]);
	printf("%d %d is eating\n", time_diff, id + 1);
	usleep(philo->eat_time * 999);
	pthread_mutex_unlock(&philo->forks[forks[0]]);
	pthread_mutex_unlock(&philo->forks[forks[1]]);
	return (1);
}

static void	ft_suicide(t_philo *philo, int id, struct timeval *interval)
{
	take_fork(philo, 0, id, interval);
	while (philo->data.death)
		;
}

void	ft_routine(t_philo *philo)
{
	struct timeval	interval;
	int				id;
	int				count;
	int				forks[2];

	id = ft_get_id(philo);
	forks[0] = id;
	if (id == 0)
		forks[1] = philo->philo_num - 1;
	else
		forks[1] = id - 1;
	count = 0;
	gettimeofday(&philo->time[id], NULL);
	if (philo->philo_num == 1)
		ft_suicide(philo, id, &interval);
	while (ft_check_death(philo))
	{
		if (!ft_eat(philo, id, forks, &interval))
			break ;
		count++;
		if (!ft_check_max_eat(philo, count, id) || !ft_check_death(philo))
			break ;
		ft_action(philo, id, philo->sleep_time, "is sleeping");
		if (!ft_check_death(philo))
			break ;
		ft_action(philo, id, 0, "is thinking");
	}
}
