/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbortolo <jbortolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 11:35:45 by jbortolo          #+#    #+#             */
/*   Updated: 2023/06/02 12:10:20 by jbortolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_putchar(char c)
{
	if (write(1, &c, 1) == -1)
		return (-1);
	return (1);
}

static int	ft_printnbr(int nb, int i)
{
	unsigned int	num;

	if (nb < 0)
	{
		if (ft_putchar('-') == -1)
			return (-1);
		num = nb * -1;
		i++;
	}
	else
	{
		num = nb;
	}
	if ((num / 10) != 0)
	{
		i = ft_printnbr(num / 10, i);
		if (i == -1)
			return (-1);
	}
	if (ft_putchar((num % 10) + 48) == -1)
		return (-1);
	i++;
	return (i);
}

int	ft_putnbr(int nb)
{
	int	i;

	i = 0;
	i = ft_printnbr(nb, i);
	return (i);
}
