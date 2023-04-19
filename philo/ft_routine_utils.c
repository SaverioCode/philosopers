/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_routine_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarzi-c <fgarzi-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 18:11:12 by fgarzi-c          #+#    #+#             */
/*   Updated: 2023/04/19 19:51:34 by fgarzi-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_get_id(t_philo *philo)
{
	int	id;

	pthread_mutex_lock(&philo->data.philo_cnt_mutex);
	id = philo->data.philo_counter;
	philo->data.philo_counter++;
	pthread_mutex_unlock(&philo->data.philo_cnt_mutex);
	return (id);
}

int	ft_check_death(t_philo *philo)
{
	int	death;

	pthread_mutex_lock(&philo->data.death_mutex);
	death = philo->data.death;
	pthread_mutex_unlock(&philo->data.death_mutex);
	return (death);
}

void	ft_check_max_eat(t_philo *philo, int count)
{
	pthread_mutex_lock(&philo->data.eat_mutex);
	if (count == philo->data.max_eat)
	{
		pthread_mutex_lock(&philo->data.death_mutex);
		philo->data.death = 0;
		pthread_mutex_unlock(&philo->data.death_mutex);
		pthread_mutex_unlock(&philo->data.eat_mutex);
	}
	pthread_mutex_unlock(&philo->data.eat_mutex);
}

int	ft_calculate_time(struct timeval *time, struct timeval *interval)
{
	int	diff;
	int	time_1;
	int	time_2;

	time_1 = (time->tv_sec * 1000000) + time->tv_usec;
	time_2 = (interval->tv_sec * 1000000) + interval->tv_usec;
	diff = time_2 - time_1;
	return (diff);
}

int	ft_check_time(t_philo *philo, struct timeval *time, int id)
{
	struct timeval	interval;
	int				time_diff;

	gettimeofday(&interval, NULL);
	time_diff = ft_calculate_time(time, &interval);
	if (time_diff / 1000 >= philo->die_time)
	{
		pthread_mutex_lock(&philo->data.death_mutex);
		philo->data.death = 0;
		pthread_mutex_unlock(&philo->data.death_mutex);
		printf("%d %d died\n", time_diff / 1000, id + 1);
		return (0);
	}
	return (1);
}
