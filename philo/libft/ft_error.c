/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarzi-c <fgarzi-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 23:11:25 by fgarzi-c          #+#    #+#             */
/*   Updated: 2023/04/05 23:11:26 by fgarzi-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"

void	ft_error(char *str)
{
	if (str)
		write(2, str, ft_strlen(str));
	else
		write(2, "Error: <message not setted>.\n", 29);
	exit(1);
}
