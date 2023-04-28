/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarzi-c <fgarzi-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 18:38:19 by fgarzi-c          #+#    #+#             */
/*   Updated: 2023/04/28 03:26:39 by fgarzi-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include "libft/libft.h"
# include <pthread.h>
# include <sys/time.h>
# include <stdio.h>
# include <semaphore.h>
# include <signal.h>

typedef struct s_philo
{
	pthread_t		master;
	struct timeval	master_time;
	int				philo_num;
	int				id;
	int				*pid;
	sem_t			*forks;
	struct timeval	time;
	int				die_time;
	int				eat_limit;
	int				eat_time;
	int				max_eat;
	int				sleep_time;
}	t_philo;

void	ft_handle_input(int ac, char **av, t_philo *philo);
void	ft_create_threads(t_philo *philo);
void	ft_free(t_philo *philo);
void	ft_routine(t_philo *philo, int id);
void	ft_check_max_eat(t_philo *philo, int count);
int		ft_calculate_time(struct timeval *time, struct timeval *interval);
void	ft_master(t_philo *philo);
void	ft_usleep(int time);

#endif
