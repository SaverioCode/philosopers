/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_threads.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarzi-c <fgarzi-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 19:49:04 by fgarzi-c          #+#    #+#             */
/*   Updated: 2023/04/17 20:52:04 by fgarzi-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_create_threads(t_philo *philo)
{
	int	i;

	if (!philo)
		ft_error("Error: create threads failes\n");
	pthread_mutex_init(&philo->data.philo_cnt_mutex, NULL);
	pthread_mutex_init(&philo->data.death_mutex, NULL);
	i = 0;
	while (i < philo->data.philo_num)
	{
		pthread_mutex_init(&philo->forks[i], NULL);
		i++;
	}
	i = 0;
	while (i < philo->data.philo_num)
	{
		pthread_create(&philo->philos[i], NULL, (void *)ft_routine, philo);
		i++;
	}
}
