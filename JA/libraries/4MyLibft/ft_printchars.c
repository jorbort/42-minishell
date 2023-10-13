/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printchars.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-anm <juan-anm@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 14:40:21 by juan-anm          #+#    #+#             */
/*   Updated: 2023/06/02 13:04:50 by juan-anm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putchars(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstrs(char *str)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	if (!str)
		return (ft_putstrs("(null)"));
	while (str[i] != 0)
	{
		if (ft_putchars((char)str[i]) == -1)
			return (-1);
	res++;
	i++;
	}
	return (res);
}
