/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarzi-c <fgarzi-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 18:38:19 by fgarzi-c          #+#    #+#             */
/*   Updated: 2023/04/13 23:39:56 by fgarzi-c         ###   ########.fr       */
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
	int				philo_num;
	pthread_mutex_t	*philo_cnt_mutex;
	int				philo_counter;
	int				max_eat;
	pthread_mutex_t	*death_mutex;
	int				death;
}	t_data;

typedef struct s_philo
{
	pthread_t		*philos;
	pthread_mutex_t	*forks;
	int				die_time;
	int				eat_time;
	int				sleep_time;
	t_data			data;
} t_philo;

void	ft_handle_input(int ac, char **av, t_philo *philo);
void	ft_create_threads(t_philo *philo);
void	ft_free(t_philo *philo);
void	ft_routine(t_philo *philo);

#endif
