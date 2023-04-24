/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarzi-c <fgarzi-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 18:38:34 by fgarzi-c          #+#    #+#             */
/*   Updated: 2023/04/24 20:36:26 by fgarzi-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	ft_kill_them_all(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->philo_num)
	{
		kill(philo->pid[i], SIGKILL);
		i++;
	}
}

int	main(int ac, char **av)
{
	t_philo	philo;

	if (ac < 5 || ac > 6)
		ft_error("Error: input parameters\n");
	ft_handle_input(ac, av, &philo);
	philo.pid = ft_calloc((philo.philo_num) * 4);
	ft_create_threads(&philo);
	usleep(1000);
	ft_free(&philo);
	exit(0);
	return (0);
}
