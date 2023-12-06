/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juanantonio <juanantonio@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 10:09:30 by juan-anm          #+#    #+#             */
/*   Updated: 2023/12/06 11:39:20 by juanantonio      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i] != 0)
	{
		ft_putchar_fd(s[i], fd);
		i++;
	}
}

void	ft_putcleanstr_fd(char *s, int fd)
{
	int	i;
	int	flag;

	flag = 0;
	i = 0;
	if (ft_isaquote(s[i]))
	{
		flag = s[i];
		while (s[i] == flag)
			i++;
	}
	while (s[i] != 0 && s[i] != flag)
	{
		ft_putchar_fd(s[i], fd);
		i++;
	}
}
