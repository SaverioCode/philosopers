/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_threads.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarzi-c <fgarzi-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 19:49:04 by fgarzi-c          #+#    #+#             */
/*   Updated: 2023/04/12 19:56:35 by fgarzi-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_create_threads(t_philo *philo)
{
	int	x;

	if (!philo)
		ft_error("Error: create threads failes\n");
	x = 0;
	while (x < philo->philo_num)
	{
		pthread_create(philo->philos[x], NULL, ft_routine, philo);
		x++;
	}
}
