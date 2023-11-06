/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbortolo <jbortolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 11:48:25 by jbortolo          #+#    #+#             */
/*   Updated: 2023/05/09 15:41:21 by jbortolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const char	*ps1;
	const char	*ps2;
	size_t		i;

	ps1 = (const char *) s1;
	ps2 = (const char *) s2;
	i = 0;
	while (i < n)
	{
		if (ps1[i] != ps2[i])
		{
			return ((unsigned char)ps1[i] - (unsigned char)ps2[i]);
		}
		i++;
	}
	return (0);
}
