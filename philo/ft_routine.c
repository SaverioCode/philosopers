/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_routine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarzi-c <fgarzi-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 16:26:26 by fgarzi-c          #+#    #+#             */
/*   Updated: 2023/04/17 16:27:04 by fgarzi-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_get_id(t_philo *philo)
{
	int	id;

	pthread_mutex_lock(&philo->data.philo_cnt_mutex);
	id = philo->data.philo_counter;
	philo->data.philo_counter++;
	pthread_mutex_unlock(&philo->data.philo_cnt_mutex);
	return (id);
}

static int	ft_check_death(t_philo *philo)
{
	int	death;

	pthread_mutex_lock(&philo->data.death_mutex);
	death = philo->data.death;
	pthread_mutex_unlock(&philo->data.death_mutex);
	return (death);
}

static void	ft_action(int time_action, t_philo *philo, int id, char *str)
{
	struct timeval	time;
	int				left_fork;

	if (str[3] == 101)
	{
		left_fork = id - 1;
		if (id == 0)
			left_fork = philo->data.philo_num - 1;
		pthread_mutex_lock(&philo->forks[left_fork]);
		pthread_mutex_lock(&philo->forks[id]);
	}
	gettimeofday(&time, NULL);
	printf("%d %d %s\n", time.tv_usec - philo->time[id].tv_usec, id + 1, str);
	usleep(time_action);
	if (str[3] == 101)
	{
		pthread_mutex_unlock(&philo->forks[left_fork]);
		pthread_mutex_unlock(&philo->forks[id]);
	}
}

static int	ft_check_time(t_philo *philo, suseconds_t time, int id)
{
	struct timeval	interval;

	gettimeofday(&interval, NULL);
	if (interval.tv_usec - time >= philo->die_time)
	{
		philo->data.death = 0;
		ft_action(0, philo, id, "died");
		return (0);
	}
	return (1);
}

void	ft_routine(t_philo *philo)
{
	int				id;
	int				count;
	struct timeval	time;

	id = ft_get_id(philo);
	count = 0;
	while (ft_check_death(philo))
	{
		if (count == 0)
			gettimeofday(&philo->time[id], NULL);
		if (count == philo->data.max_eat)
			break ;
		if (count > 0 && !ft_check_time(philo, time.tv_usec, id))
			break ;
		ft_action(philo->eat_time, philo, id, "is eating");
		gettimeofday(&time, NULL);
		if (!ft_check_death(philo))
			break ;
		ft_action(philo->sleep_time, philo, id, "is sleeping");
		if (!ft_check_death(philo) || !ft_check_time(philo, time.tv_usec, id))
			break ;
		ft_action(0, philo, id, "is thinking");
		count++;
	}
}
