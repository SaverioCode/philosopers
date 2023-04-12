/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopers.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarzi-c <fgarzi-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 18:38:19 by fgarzi-c          #+#    #+#             */
/*   Updated: 2023/04/12 16:15:47 by fgarzi-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include "libft/libft.h"
# include <pthread.h>
# include <sys/time.h>

typedef struct s_philo
{
	int	tot_philos;
	int	*philos;
	int	die_time;
	int	eat_time;
	int	sleep_time;
	int	max_eat;
	
} t_philo;

#endif
