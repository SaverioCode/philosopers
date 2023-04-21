/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarzi-c <fgarzi-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 18:38:19 by fgarzi-c          #+#    #+#             */
/*   Updated: 2023/04/21 05:03:27 by fgarzi-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include "libft/libft.h"
# include <pthread.h>
# include <sys/time.h>
# include <stdio.h>

typedef struct s_data
{
	pthread_mutex_t	philo_cnt_mutex;
	int				philo_counter;
	pthread_mutex_t	eat_mutex;
	int				max_eat;
	pthread_mutex_t	death_mutex;
	int				death;
}	t_data;

typedef struct s_philo
{
	pthread_t		master;
	struct timeval	master_time;
	int				philo_num;
	pthread_t		*philos;
	pthread_mutex_t	*forks;
	struct timeval	*time;
	int				die_time;
	int				*eat_limit;
	int				eat_time;
	int				sleep_time;
	t_data			data;
}	t_philo;

void	ft_handle_input(int ac, char **av, t_philo *philo);
void	ft_create_threads(t_philo *philo);
void	ft_free(t_philo *philo);
void	ft_routine(t_philo *philo);
int		ft_get_id(t_philo *philo);
int		ft_check_death(t_philo *philo);
int		ft_check_max_eat(t_philo *philo, int count, int id);
int		ft_check_time(t_philo *philo, int id);
int		ft_calculate_time(struct timeval *time, struct timeval *interval);
void	ft_master(t_philo *philo);

#endif
