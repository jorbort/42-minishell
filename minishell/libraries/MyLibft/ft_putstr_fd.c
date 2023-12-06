/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juanantonio <juanantonio@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 10:09:30 by juan-anm          #+#    #+#             */
/*   Updated: 2023/12/06 10:52:32 by juanantonio      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
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
