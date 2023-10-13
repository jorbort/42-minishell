/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-anm <juan-anm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 16:52:06 by juan-anm          #+#    #+#             */
/*   Updated: 2023/05/11 14:10:14 by juan-anm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_fillnum(char *itoa, int n, int len);
static int		ft_intlen(int n);

char	*ft_itoa(int n)
{
	int				neg;
	int				i;
	char			*itoa;

	i = 0;
	neg = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	else if (n < 0)
	{
		n = n * -1;
		neg = 1;
	}
	itoa = malloc(ft_intlen(n) + neg * sizeof(char) + 1);
	if (!itoa)
		return (0);
	if (neg == 1)
	{
		itoa[i] = '-';
		i++;
	}
	ft_fillnum(&itoa[i], n, ft_intlen(n));
	return (itoa);
}

static int	ft_intlen(int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
	n = n / 10;
	i++;
	}
	return (i);
}

static void	ft_fillnum(char *itoa, int n, int len)
{
	int	i;
	int	div;

	i = 0;
	div = 1;
	while (len > 1)
	{
		div = div * 10;
	len--;
	}
	while (div > 0)
	{
		itoa[i] = '0' + (n / div);
		n = n % div;
		div = div / 10;
	i++;
	}
	itoa[i] = 0;
}

/*#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	printf("%s", ft_itoa(10020));
}*/
