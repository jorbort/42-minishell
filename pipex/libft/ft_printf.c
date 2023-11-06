/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbortolo <jbortolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 12:41:06 by jbortolo          #+#    #+#             */
/*   Updated: 2023/07/17 13:42:27 by jbortolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	var_type(va_list parameters, char const *s, int j)
{
	if (s[j + 1] == '%')
		return (write(1, "%", 1));
	if (s[j + 1] == 'c')
		return (ft_putchar_par(va_arg(parameters, int)));
	if (s[j + 1] == 's')
		return (ft_putstr(va_arg(parameters, char *)));
	if (s[j + 1] == 'p')
		return (print_pointer_hex(va_arg(parameters, unsigned long)));
	if (s[j + 1] == 'd' || s[j + 1] == 'i')
		return (ft_putnbr(va_arg(parameters, int)));
	if (s[j + 1] == 'u')
		return (ft_putnbr_unsigned(va_arg(parameters, unsigned int)));
	if (s[j + 1] == 'x' || s[j + 1] == 'X')
		return (ft_putnbr_base(va_arg(parameters, long), &s[j + 1]));
	return (0);
}

static int	str_parse(va_list parameters, char const *s)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (s[j])
	{
		if (s[j] == '%')
		{
			i += var_type(parameters, s, j);
			if (i < 0)
				return (-1);
			j += 2;
		}
		else
		{
			if (write(1, &s[j], 1) != -1)
				i++;
			else
				return (i = -1);
			j++;
		}
	}
	return (i);
}

int	ft_printf(char const *c, ...)
{
	va_list	parameters;
	int		i;

	i = 0;
	va_start(parameters, c);
	i = str_parse(parameters, c);
	va_end(parameters);
	return (i);
}
