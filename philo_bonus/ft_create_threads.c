/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_threads.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarzi-c <fgarzi-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 19:49:04 by fgarzi-c          #+#    #+#             */
/*   Updated: 2023/04/25 00:48:12 by fgarzi-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_create_threads(t_philo *philo)
{
	int	i;

	if (!philo)
		ft_error("Error: create threads failes\n");
	printf("SEM_UNLINK: %d\n", sem_unlink("/forks"));
	philo->forks = sem_open("/forks", O_CREAT, S_IROTH | S_IWOTH, philo->philo_num);
	if (philo->forks == SEM_FAILED)
		printf("PORCODIO\n");
	i = 0;
	gettimeofday(&philo->master_time, NULL);
	while (i < philo->philo_num)
	{
		ft_routine(philo, i);
		usleep(10);
		i++;
	}
}
