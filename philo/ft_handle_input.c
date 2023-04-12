/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_input.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarzi-c <fgarzi-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 23:35:53 by fgarzi-c          #+#    #+#             */
/*   Updated: 2023/04/05 23:43:32 by fgarzi-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopers.h"

void	ft_handle_input(int ac, char **av, t_philo *philo)
{
	philo->tot_philos = av[1];
	if (philo->tot_philos < 1)
		ft_error("Error: number of philos has to be at least 1");
	philo->philos = ft_calloc(philo->tot_philos + 1);
	philo->die_time = ft_atoi(av[2]);
	philo->eat_time = ft_atoi(av[3]);
	philo->sleep_time = ft_atoi(av[4]);
	if (ac == 6)
		philo->max_eat = ft_atoi(av[5]);
}
