/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_routine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarzi-c <fgarzi-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 16:26:26 by fgarzi-c          #+#    #+#             */
/*   Updated: 2023/04/13 23:49:17 by fgarzi-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_routine(t_philo *philo)
{
	int	philo_id;
	
	pthread_mutex_lock(philo->data.philo_cnt_mutex);
	philo_id = philo->data.philo_counter;
	philo->data.philo_counter++;
	pthread_mutex_unlock(philo->data.philo_cnt_mutex);
	pthread_mutex_lock(philo->data.death_mutex);
	while (philo->data.death)
	{
		pthread_mutex_unlock(philo->data.death_mutex);
		pthread_mutex_unlock(&philo->forks[philo_id - 1]);
		ptread_mutex_unlock(&philo->forks[philo_id + 1]);
		pthread_mutex_lock(philo->data.death_mutex);
	}
	write(1, "ciao\n", 5);
}
