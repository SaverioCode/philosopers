/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_threads.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarzi-c <fgarzi-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 19:49:04 by fgarzi-c          #+#    #+#             */
/*   Updated: 2023/04/24 18:49:27 by fgarzi-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_create_threads(t_philo *philo)
{
	int	i;

	if (!philo)
		ft_error("Error: create threads failes\n");
	philo->forks = sem_open("/forks", O_CREAT, S_IRUSR | S_IWUSR, philo->philo_num);
	i = 0;
	gettimeofday(&philo->master_time, NULL);
	while (i < philo->philo_num)
	{
		ft_routine(philo, i);
		usleep(10);
		i++;
	}
}
