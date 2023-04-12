/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarzi-c <fgarzi-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 20:55:02 by fgarzi-c          #+#    #+#             */
/*   Updated: 2023/04/12 20:58:16 by fgarzi-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_free(t_philo *philo)
{
	int	i;

	if (!philo)
		ft_error("Error: final free failed\n");
	i = 0;
	while (i < philo->philo_num)
	{
		pthread_mutex_destroy(&philo->forks[i]);
		i++;
	}
	free(philo->philos);
	free(philo->forks);
}
