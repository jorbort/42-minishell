/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnumber_base.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbortolo <jbortolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 17:21:37 by jbortolo          #+#    #+#             */
/*   Updated: 2023/07/17 13:42:33 by jbortolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	printnbr_long(unsigned long long n, char *symbols, int i)
{
	if (n >= 16)
	{
		i = printnbr_long(n / 16, symbols, i);
		if (i == -1)
			return (-1);
		if (write(1, &symbols[n % 16], 1) == -1)
			return (-1);
		i++;
	}
	else if (n < 16)
	{
		if (write(1, &symbols[n], 1) == -1)
			return (-1);
		i++;
	}
	return (i);
}

static int	printnbr_uns(unsigned int n, char *symbols, int i)
{
	if (n >= 16)
	{
		i = printnbr_uns(n / 16, symbols, i);
		if (i == -1)
			return (-1);
		if (write(1, &symbols[n % 16], 1) == -1)
			return (-1);
		i++;
	}
	else if (n < 16)
	{
		if (write(1, &symbols[n], 1) == -1)
			return (-1);
		i++;
	}
	return (i);
}

int	ft_putnbr_base(int nbr, const char *j)
{
	int	i;

	i = 0;
	if (*j == 'x')
	{
		if (nbr >= 0)
			i = printnbr_long(nbr, "0123456789abcdef", i);
		else if (nbr < 0)
			i = printnbr_uns(nbr, "0123456789abcdef", i);
	}
	else if (*j == 'X')
	{
		if (nbr >= 0)
			i = printnbr_long(nbr, "0123456789ABCDEF", i);
		else if (nbr < 0)
			i = printnbr_uns(nbr, "0123456789ABCDEF", i);
	}
	return (i);
}
