/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_routine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarzi-c <fgarzi-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 16:26:26 by fgarzi-c          #+#    #+#             */
/*   Updated: 2023/04/13 22:30:38 by fgarzi-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_routine(t_philo *philo)
{
	int		id;
	// char 	*str;
	int		len;
	
	
	id = (int)philo->philos[0];
	// str = ft_itoa(id);
	len = ft_numlen(id, 10);
	printf("%d\n", id);
	// write(1, str, len);
	// free(str);
	write(1, "ciao\n", 5);
}
