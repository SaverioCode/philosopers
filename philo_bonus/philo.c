/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarzi-c <fgarzi-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 18:38:34 by fgarzi-c          #+#    #+#             */
/*   Updated: 2023/04/25 00:59:55 by fgarzi-c         ###   ########.fr       */
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
	int		status;

	if (ac < 5 || ac > 6)
		ft_error("Error: input parameters\n");
	ft_handle_input(ac, av, &philo);
	philo.eat_limit = 0;
	philo.pid = ft_calloc((philo.philo_num) * 4);
	ft_create_threads(&philo);
	waitpid(-1, &status, 0);
	printf("GURADA QUA: %d\n", WIFEXITED(status));////
	if (WIFEXITED(status))
	{	
		write(1, "here\n", 5);///
		ft_kill_them_all(&philo);
	}
	usleep(1000000);
	ft_free(&philo);
	exit(0);
	return (0);
}
