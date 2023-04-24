/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_routine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarzi-c <fgarzi-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 16:26:26 by fgarzi-c          #+#    #+#             */
/*   Updated: 2023/04/25 00:17:27 by fgarzi-c         ###   ########.fr       */
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

static void	take_fork(t_philo *philo, int id)
{
	struct timeval	interval;
	int				time_diff;

	sem_wait(philo->forks);
	gettimeofday(&interval, NULL);
	time_diff = ft_calculate_time(&philo->master_time, &interval);
	printf("%d %d has taken a fork\n", time_diff, id + 1);
}

static void	ft_eat(t_philo *philo, int id)
{
	int				time_diff;

	take_fork(philo, id);
	take_fork(philo, id);
	gettimeofday(&philo->time, NULL);
	time_diff = ft_calculate_time(&philo->master_time, &philo->time);
	printf("%d %d is eating\n", time_diff, id + 1);
	usleep(philo->eat_time * 1000);
	sem_post(philo->forks);
	sem_post(philo->forks);
}

void	ft_routine(t_philo *philo, int id)
{
	int		count;
	int		pid;

	pid = fork();
	if (pid == 0)
		return ;
	philo->pid[id] = pid;
	philo->id = id;
	pthread_create(&philo->master, NULL, (void *)ft_master, philo);
	count = 0;
	gettimeofday(&philo->time, NULL);
	while (1)
	{
		ft_eat(philo, id);
		count++;
		ft_check_max_eat(philo, count);
		ft_action(philo, id, philo->sleep_time, "is sleeping");
		ft_action(philo, id, 0, "is thinking");
	}
}
