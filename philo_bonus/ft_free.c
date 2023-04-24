/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarzi-c <fgarzi-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 20:55:02 by fgarzi-c          #+#    #+#             */
/*   Updated: 2023/04/24 15:41:54 by fgarzi-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_free(t_philo *philo)
{
	int	i;

	if (!philo)
		ft_error("Error: final free failed\n");
	i = 0;
	sem_close(philo->data.death);
	sem_unlink("/death");
	sem_close(philo->data.philo_id);
	sem_unlink("/philo_id");
	sem_close(philo->forks);
	sem_unlink("/forks");
	free(philo->eat_limit);
	free(philo->time);
}
