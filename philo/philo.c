/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarzi-c <fgarzi-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 18:38:34 by fgarzi-c          #+#    #+#             */
/*   Updated: 2023/04/17 16:22:35 by fgarzi-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_philo	philo;

	if (ac < 5 || ac > 6)
		ft_error("Error: input parameters\n");
	philo.data.philo_counter = -1;
	philo.data.death = 1;
	ft_handle_input(ac, av, &philo);
	philo.time = calloc(philo.data.philo_num + 1, 4);
	ft_create_threads(&philo);
	while (philo.data.death == 1)
		usleep(philo.die_time + philo.eat_time + philo.eat_time);
	ft_free(&philo);
	return (0);
}
