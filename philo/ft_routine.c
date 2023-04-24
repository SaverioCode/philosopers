/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_routine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarzi-c <fgarzi-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 16:26:26 by fgarzi-c          #+#    #+#             */
/*   Updated: 2023/04/24 18:12:21 by fgarzi-c         ###   ########.fr       */
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
	usleep(time * 1000);
}

static void	take_fork(t_philo *philo, int fork, int id)
{
	struct timeval	interval;
	int				time_diff;

	pthread_mutex_lock(&philo->forks[fork]);
	gettimeofday(&interval, NULL);
	time_diff = ft_calculate_time(&philo->master_time, &interval);
	printf("%d %d has taken a fork\n", time_diff, id + 1);
}

static int	ft_eat(t_philo *philo, int id)
{
	int				left_fork;
	int				time_diff;

	left_fork = id - 1;
	if (id == philo->philo_num)
		left_fork = philo->philo_num - 1;
	if (id % 2 == 0)
	{
		take_fork(philo, id, id);
		take_fork(philo, left_fork, id);
	}
	else
	{
		take_fork(philo, left_fork, id);
		take_fork(philo, id, id);
	}
	gettimeofday(&philo->time[id], NULL);
	if (!philo->data.death)
		return (0);
	time_diff = ft_calculate_time(&philo->master_time, &philo->time[id]);
	printf("%d %d is eating\n", time_diff, id + 1);
	usleep(philo->eat_time * 1000);
	pthread_mutex_unlock(&philo->forks[left_fork]);
	pthread_mutex_unlock(&philo->forks[id]);
	return (1);
}

static void	ft_suicide(t_philo *philo, int id)
{
	take_fork(philo, 0, id);
	while (philo->data.death)
		;
}

void	ft_routine(t_philo *philo)
{
	int		id;
	int		count;

	id = ft_get_id(philo);
	count = 0;
	gettimeofday(&philo->time[id], NULL);
	if (philo->philo_num == 1)
		ft_suicide(philo, id);
	while (philo->data.death)
	{
		if (!ft_eat(philo, id))
			break ;
		count++;
		if (!ft_check_max_eat(philo, count, id) || !philo->data.death)
			return ;
		ft_action(philo, id, philo->sleep_time, "is sleeping");
		if (!philo->data.death)
			break ;
		ft_action(philo, id, 0, "is thinking");
	}
}
