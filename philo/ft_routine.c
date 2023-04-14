/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_routine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarzi-c <fgarzi-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 16:26:26 by fgarzi-c          #+#    #+#             */
/*   Updated: 2023/04/14 18:29:22 by fgarzi-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_check_death(t_philo philo)
{

}

static void	ft_action(int time_action, t_philo *philo, int id, char *str)
{
	int	time;
	int	left_fork;

	if (str[3] == 101)
	{
		left_fork = id - 1;
		if (id == 0)
			left_fork = philo->data.philo_num - 1;
		pthread_mutex_lock(&philo->forks[left_fork]);
		pthread_mutex_lock(&philo->forks[id]);
	}
	gettimeofday(time, NULL);
	printf("%d %d %s\n", philo->time[id] - time, id + 1, str);
	usleep(time_action);
	if (str[3] == 101)
	{
		pthread_mutex_unlock(&philo->forks[left_fork]);
		pthread_mutex_unlock(&philo->forks[id]);
	}
}

void	ft_routine(t_philo *philo)
{
	int	philo_id;
	int	count;

	pthread_mutex_lock(philo->data.philo_cnt_mutex);
	philo_id = philo->data.philo_counter;
	philo->data.philo_counter++;
	pthread_mutex_unlock(philo->data.philo_cnt_mutex);
	pthread_mutex_lock(philo->data.death_mutex);
	while (philo->data.death)
	{
		pthread_mutex_unlock(philo->data.death_mutex);
		gettimeofday(philo->time[philo_id], NULL);
		ft_action(philo->eat_time, philo, philo_id, "is eating");
		if (!ft_check_deat(philo))
			break;
		ft_action(philo->sleep_time, philo, philo_id, "is sleeping");
		if (!ft_check_deat(philo))
			break;
		ft_action(0, philo, philo_id, "is thinking");
		pthread_mutex_lock(philo->data.death_mutex);
	}
	ft_action(0, philo, philo_id, "died");
}
