/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_threads.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarzi-c <fgarzi-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 19:49:04 by fgarzi-c          #+#    #+#             */
/*   Updated: 2023/04/13 23:44:43 by fgarzi-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_create_threads(t_philo *philo)
{
	int	i;

	if (!philo)
		ft_error("Error: create threads failes\n");
	i = 0;
	pthread_mutex_init(philo->data.philo_cnt_mutex, NULL);
	pthread_mutex_init(philo->data.death_mutex, NULL);
	while (i < philo->data.philo_num)
	{
		pthread_create(&philo->philos[i], NULL, (void *)ft_routine, philo);
		pthread_mutex_init(&philo->forks[0], NULL);
		i++;
	}
}
