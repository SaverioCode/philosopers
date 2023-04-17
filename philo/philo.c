/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarzi-c <fgarzi-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 18:38:34 by fgarzi-c          #+#    #+#             */
/*   Updated: 2023/04/17 18:31:28 by fgarzi-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_philo	philo;

	if (ac < 5 || ac > 6)
		ft_error("Error: input parameters\n");
	philo.data.philo_counter = 0;
	philo.data.death = 1;
	ft_handle_input(ac, av, &philo);
	philo.time = calloc(philo.data.philo_num + 1, 4);
	ft_create_threads(&philo);
	while (1)
	{
		pthread_mutex_lock(&philo.data.death_mutex);
		if (!philo.data.death)
		{
			pthread_mutex_unlock(&philo.data.death_mutex);
			break ;
		}
		pthread_mutex_unlock(&philo.data.death_mutex);
	}
	usleep(1000);
	ft_free(&philo);
	return (0);
}
