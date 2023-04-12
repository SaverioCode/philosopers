/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarzi-c <fgarzi-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 18:38:34 by fgarzi-c          #+#    #+#             */
/*   Updated: 2023/04/12 16:16:10 by fgarzi-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_philo	philo;

	if (ac < 4 || ac > 5)
		ft_error("Error: input parameters");
	ft_handle_input(ac, av, philo);
	pthread_create();
	free(philo.philos);
	return (0);
}
