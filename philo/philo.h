/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarzi-c <fgarzi-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 18:38:19 by fgarzi-c          #+#    #+#             */
/*   Updated: 2023/04/13 16:45:49 by fgarzi-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include "libft/libft.h"
# include <pthread.h>
# include <sys/time.h>
# include <stdio.h>

typedef struct s_philo
{
	int				philo_num;
	pthread_t		*philos;
	pthread_mutex_t	*forks;
	int				die_time;
	int				eat_time;
	int				sleep_time;
	int				max_eat;
} t_philo;

void	ft_handle_input(int ac, char **av, t_philo *philo);
void	ft_create_threads(t_philo *philo);
void	ft_free(t_philo *philo);
void	ft_routine(t_philo *philo);

#endif
