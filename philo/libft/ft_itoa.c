/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarzi-c <fgarzi-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 23:11:30 by fgarzi-c          #+#    #+#             */
/*   Updated: 2023/04/17 14:46:56 by fgarzi-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(long num)
{
	int		strlen;
	char	*strnum;

	if (!num || num < INT_MIN || num > INT_MAX)
		return (NULL);
	if (num == 0)
	{
		strnum = ft_calloc(1);
		strnum[0] = 48;
		return (strnum);
	}
	strlen = ft_numlen(num, 10);
	strnum = ft_calloc(strlen);
	if (num < 0)
	{
		strnum[0] = 45;
		num *= -1;
	}
	while (num > 0)
	{
		strlen--;
		strnum[strlen] = (num % 10) + 48;
		num /= 10;
	}
	return (strnum);
}
