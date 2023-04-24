/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarzi-c <fgarzi-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 18:38:34 by fgarzi-c          #+#    #+#             */
/*   Updated: 2023/04/24 16:49:24 by fgarzi-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_philo	philo;

	if (ac < 5 || ac > 6)
		ft_error("Error: input parameters\n");
	ft_handle_input(ac, av, &philo);
	philo.eat_limit = ft_calloc((philo.philo_num + 1) * 4);
	philo.time = ft_calloc((philo.philo_num + 1) * sizeof(struct timeval));
	philo.pid = ft_calloc((philo.philo_num) * 4);
	ft_create_threads(&philo);
	ft_master(&philo);
	usleep(1000);
	ft_free(&philo);
	exit(0);
	return (0);
}
