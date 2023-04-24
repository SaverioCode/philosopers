/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_input.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarzi-c <fgarzi-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 23:35:53 by fgarzi-c          #+#    #+#             */
/*   Updated: 2023/04/24 16:49:56 by fgarzi-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_handle_input(int ac, char **av, t_philo *philo)
{
	if (!ac || !av || !philo)
		ft_error("Error: handle input failed\n");
	philo->philo_num = ft_atoi(av[1]);
	if (philo->philo_num < 1)
		ft_error("Error: number of philos has to be at least 1\n");
	philo->die_time = ft_atoi(av[2]);
	philo->eat_time = ft_atoi(av[3]);
	philo->sleep_time = ft_atoi(av[4]);
	if (philo->die_time <= 0 || philo->eat_time < 1 || philo->sleep_time < 1)
		ft_error("Error: parameters have to be > 0\n");
	if (ac == 6)
	{	
		philo->max_eat = ft_atoi(av[5]);
		if (philo->max_eat < 1)
			ft_error("Error: parameters have to be > 0\n");
	}
}
