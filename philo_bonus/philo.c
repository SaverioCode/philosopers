/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarzi-c <fgarzi-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 18:38:34 by fgarzi-c          #+#    #+#             */
/*   Updated: 2023/04/24 15:42:52 by fgarzi-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// static int	ft_check_eating(t_philo *philo)
// {
// 	int	i;
// 	int	c;

// 	c = 0;
// 	i = 0;
// 	while (i < philo->philo_num)
// 	{
// 		if (philo->eat_limit[i] == 1)
// 			c++;
// 		i++;
// 	}
// 	if (c == philo->philo_num)
// 	{
// 		pthread_mutex_lock(&philo->data.death_mutex);
// 		philo->data.death = 0;
// 		pthread_mutex_unlock(&philo->data.death_mutex);
// 		return (0);
// 	}
// 	return (1);
// }

int	main(int ac, char **av)
{
	t_philo	philo;

	if (ac < 5 || ac > 6)
		ft_error("Error: input parameters\n");
	ft_handle_input(ac, av, &philo);
	philo.eat_limit = ft_calloc((philo.philo_num + 1) * 4);
	philo.time = ft_calloc((philo.philo_num + 1) * sizeof(struct timeval));
	write(1, "here\n", 5);/////
	ft_create_threads(&philo);
	write(1, "here1\n", 6);/////
	ft_master(&philo);
	usleep(1000);
	ft_free(&philo);
	exit(0);
	return (0);
}
