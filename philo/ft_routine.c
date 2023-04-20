/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_routine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarzi-c <fgarzi-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 16:26:26 by fgarzi-c          #+#    #+#             */
/*   Updated: 2023/04/20 21:54:37 by fgarzi-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	ft_sleep(t_philo *philo, int id)
{
	struct timeval	interval;
	int				time_diff;

	gettimeofday(&interval, NULL);
	time_diff = ft_calculate_time(&philo->master_time, &interval);
	printf("%d %d is sleeping\n", time_diff / 1000, id + 1);
	usleep(philo->sleep_time * 1000);
}

static void	ft_think(t_philo *philo, int id)
{
	struct timeval	interval;
	int				time_diff;

	gettimeofday(&interval, NULL);
	time_diff = ft_calculate_time(&philo->master_time, &interval);
	printf("%d %d is thinking\n", time_diff / 1000, id + 1);
}

static void	take_fork(t_philo *philo, int fork, int id)
{
	struct timeval	interval;
	int				time_diff;

	gettimeofday(&interval, NULL);
	time_diff = ft_calculate_time(&philo->master_time, &interval);
	printf("%d %d has taken a fork\n", time_diff / 1000, id + 1);
	pthread_mutex_lock(&philo->forks[fork]);

}

static int	ft_eat(t_philo *philo, int id)
{
	int				left_fork;
	int				time_diff;
	
	left_fork = id - 1;
	if (id == 0)
		left_fork = philo->data.philo_num - 1;
	take_fork(philo, left_fork, id);
	take_fork(philo, id, id);
	gettimeofday(&philo->time[id], NULL);
	if (!ft_check_death(philo))
	{
		pthread_mutex_unlock(&philo->forks[left_fork]);
		pthread_mutex_unlock(&philo->forks[id]);
		return (0);
	}
	time_diff = ft_calculate_time(&philo->master_time, &philo->time[id]);
	printf("%d %d is eating\n", time_diff / 1000, id + 1);
	usleep(philo->eat_time * 1000);
	pthread_mutex_unlock(&philo->forks[left_fork]);
	pthread_mutex_unlock(&philo->forks[id]);
	return (1);
}

void	ft_routine(t_philo *philo)
{
	int				id;
	int				count;

	id = ft_get_id(philo);
	count = 0;
	gettimeofday(&philo->time[id], NULL);
	while (ft_check_death(philo))
	{
		if (!ft_check_death(philo))
			break ;
		if (!ft_eat(philo, id))
			break ;
		count++;
		ft_check_max_eat(philo, count);
		if (!ft_check_death(philo))
			break ;
		ft_sleep(philo, id);
		if (!ft_check_death(philo))
			break ;
		ft_think(philo, id);
	}
}
