/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbortolo <jbortolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 12:54:47 by jbortolo          #+#    #+#             */
/*   Updated: 2023/06/02 12:11:23 by jbortolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_putchar(char c)
{
	if (write(1, &c, 1) == -1)
		return (-1);
	return (1);
}

int	ft_putnbr_unsigned(unsigned int nb)
{
	int	i;

	i = 0;
	if (nb > 9)
	{
		i = ft_putnbr_unsigned(nb / 10);
		if (i == -1)
			return (-1);
		nb = nb % 10;
	}
	if (nb <= 9)
	{
		if (ft_putchar(('0' + nb)) == -1)
			return (-1);
		i++;
	}
	return (i);
}
