/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarzi-c <fgarzi-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 20:55:02 by fgarzi-c          #+#    #+#             */
/*   Updated: 2023/04/17 18:52:25 by fgarzi-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_free(t_philo *philo)
{
	int	i;

	if (!philo)
		ft_error("Error: final free failed\n");
	i = 0;
	pthread_mutex_destroy(&philo->data.death_mutex);
	pthread_mutex_destroy(&philo->data.philo_cnt_mutex);
	while (i < philo->data.philo_num)
	{
		pthread_mutex_destroy(&philo->forks[i]);
		i++;
	}
	free(philo->time);
	free(philo->philos);
	free(philo->forks);
}
