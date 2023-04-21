/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarzi-c <fgarzi-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 18:38:34 by fgarzi-c          #+#    #+#             */
/*   Updated: 2023/04/21 05:10:05 by fgarzi-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_check_eating(t_philo *philo)
{
	int	i;
	int	c;

	c = 0;
	i = 0;
	while (i < philo->philo_num)
	{
		if (philo->eat_limit[i] == 1)
			c++;
		i++;
	}
	if (c == philo->philo_num)
	{
		pthread_mutex_lock(&philo->data.death_mutex);
		philo->data.death = 0;
		pthread_mutex_unlock(&philo->data.death_mutex);
		return (0);
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_philo	philo;

	if (ac < 5 || ac > 6)
		ft_error("Error: input parameters\n");
	philo.data.philo_counter = 0;
	philo.data.death = 1;
	ft_handle_input(ac, av, &philo);
	philo.eat_limit = ft_calloc((philo.philo_num + 1) * 4);
	philo.time = ft_calloc((philo.philo_num + 1) * sizeof(struct timeval));
	ft_create_threads(&philo);
	while (1)
		if (!ft_check_death(&philo) || !ft_check_eating(&philo))
			break ;
	usleep(100);
	ft_free(&philo);
	return (0);
}
