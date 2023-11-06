/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbortolo <jbortolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 09:50:13 by jbortolo          #+#    #+#             */
/*   Updated: 2023/07/17 13:41:19 by jbortolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	int_len(int nb)
{
	int	len;

	len = 1;
	if (nb < 0)
	{
		len++;
	}
	while (nb / 10 != 0)
	{
		nb = nb / 10;
		len++;
	}
	return (len);
}

static int	base(int len)
{
	int	base;

	base = 1;
	while (len-- > 0)
	{
		base *= 10;
	}
	return (base);
}

char	*ft_itoa(int n)
{
	char			*ptr;
	unsigned int	nb;
	int				len;
	int				i;

	i = 0;
	len = int_len(n);
	ptr = malloc(sizeof(char) * len + 1);
	if (!ptr)
		return (NULL);
	if (n < 0)
	{
		nb = -n;
		ptr[i++] = '-';
		len--;
	}
	else
		nb = n;
	while (len-- > 0)
	{
		ptr[i++] = (nb / base(len)) + 48;
		nb = nb % base(len);
	}
	ptr[i] = '\0';
	return (ptr);
}
