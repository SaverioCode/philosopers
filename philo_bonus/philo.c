/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarzi-c <fgarzi-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 18:38:34 by fgarzi-c          #+#    #+#             */
/*   Updated: 2023/04/28 02:52:13 by fgarzi-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	kill_them_all(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->philo_num)
	{
		kill(philo->pid[i], SIGKILL);
		i++;
	}
	usleep(100);
}

static int	get_id(t_philo *philo, int pid)
{
	int	i;

	i = 0;
	while (i < philo->philo_num)
	{
		if (philo->pid[i] == pid)
			return (i);
		i++;
	}
	return (-1);
}

static void	print_death(t_philo *philo, int pid)
{
	struct timeval	interval;
	int				time_diff;
	int				id;

	gettimeofday(&interval, NULL);
	time_diff = ft_calculate_time(&philo->master_time, &interval);
	id = get_id(philo, pid);
	printf("%d %d died\n", time_diff, id + 1);
}

int	main(int ac, char **av)
{
	t_philo		philo;
	int			status;
	pid_t		child;
	static int	i;

	if (ac < 5 || ac > 6)
		ft_error("Error: input parameters\n");
	ft_handle_input(ac, av, &philo);
	philo.eat_limit = 0;
	philo.pid = ft_calloc((philo.philo_num) * 4);
	ft_create_threads(&philo);
	while (i != philo.philo_num)
	{
		child = waitpid(-1, &status, 0);
		if (WSTOPSIG(status) == 3)
		{
			kill_them_all(&philo);
			print_death(&philo, child);
			break ;
		}
		else if (WSTOPSIG(status) == 2)
			i++;
	}
	ft_free(&philo);
	return (0);
}
