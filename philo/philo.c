/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarzi-c <fgarzi-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 18:38:34 by fgarzi-c          #+#    #+#             */
/*   Updated: 2023/04/26 22:28:44 by fgarzi-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_choose_fork(int philo_num, int id)
{
	if (id == 0)
		return (philo_num - 1);
	else
		return (id - 1);
}

int	main(int ac, char **av)
{
	t_philo	philo;

	philo.data.eat_flag = 0;
	if (ac < 5 || ac > 6)
		ft_error("Error: input parameters\n");
	philo.data.philo_counter = 0;
	philo.data.death = 1;
	philo.master_value = 1;
	ft_handle_input(ac, av, &philo);
	philo.eat_limit = ft_calloc((philo.philo_num + 1) * 4);
	philo.time = ft_calloc((philo.philo_num + 1) * sizeof(struct timeval));
	ft_create_threads(&philo);
	while (philo.master_value)
		;
	ft_free(&philo);
	return (0);
}
