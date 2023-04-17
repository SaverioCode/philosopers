/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarzi-c <fgarzi-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 18:38:34 by fgarzi-c          #+#    #+#             */
/*   Updated: 2023/04/17 20:40:55 by fgarzi-c         ###   ########.fr       */
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
	philo.time = calloc(philo.data.philo_num + 1, sizeof(struct timeval));
	ft_create_threads(&philo);
	usleep(100000);
	ft_free(&philo);
	return (0);
}
