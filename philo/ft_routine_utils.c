/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_routine_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarzi-c <fgarzi-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 18:11:12 by fgarzi-c          #+#    #+#             */
/*   Updated: 2023/04/21 05:03:44 by fgarzi-c         ###   ########.fr       */
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

int	ft_check_max_eat(t_philo *philo, int count, int id)
{
	if (count == philo->data.max_eat)
	{
		philo->eat_limit[id] = 1;
		return (0);
	}
	return (1);
}

int	ft_calculate_time(struct timeval *time, struct timeval *interval)
{
	int					diff;
	unsigned long long	time_1;
	unsigned long long	time_2;

	time_1 = (time->tv_sec * 1000) + (time->tv_usec / 1000);
	time_2 = (interval->tv_sec * 1000) + (interval->tv_usec / 1000);
	diff = time_2 - time_1;
	return (diff);
}
