/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_routine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarzi-c <fgarzi-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 16:26:26 by fgarzi-c          #+#    #+#             */
/*   Updated: 2023/04/13 23:25:23 by fgarzi-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_routine(t_philo *philo)
{
	pthread_mutex_lock(philo->data.death_mutex);
	while (philo->data.death)
	{
		pthread_mutex_unlock(philo->data.death_mutex);
		
		pthread_mutex_lock(philo->data.death_mutex);
	}
	write(1, "ciao\n", 5);
}
