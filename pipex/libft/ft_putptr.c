/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbortolo <jbortolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 15:00:39 by jbortolo          #+#    #+#             */
/*   Updated: 2023/07/17 13:42:46 by jbortolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_putptr(unsigned long ptr, char *symbols, int i)
{
	if (ptr >= 16)
	{
		i = ft_putptr(ptr / 16, symbols, i);
		if (i == -1)
			return (-1);
		if (write(1, &symbols[ptr % 16], 1) == -1)
			return (-1);
		i++;
	}
	else if (ptr < 16)
	{
		if (write(1, &symbols[ptr], 1) == -1)
			return (-1);
		i++;
	}
	return (i);
}

int	print_pointer_hex(unsigned long parameters)
{
	int	i;

	i = 0;
	if (write(1, "0x", 2) != 2)
		return (i = -1);
	i += ft_putptr(parameters, "0123456789abcdef", i);
	if (i < 0)
		return (i = -1);
	else
		return (i += 2);
}
