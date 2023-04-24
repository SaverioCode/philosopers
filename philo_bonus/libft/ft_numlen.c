/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarzi-c <fgarzi-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 23:11:34 by fgarzi-c          #+#    #+#             */
/*   Updated: 2023/04/13 16:42:58 by fgarzi-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_numlen(long long num, int base)
{
	int	counter;

	if (base < 2)
		ft_error("Error: number base to low!\n");
	counter = 0;
	if (num < 0)
	{
		num *= -1;
		counter++;
	}
	while (num > 0)
	{	
		num /= base;
		counter++;
	}
	return (counter);
}
