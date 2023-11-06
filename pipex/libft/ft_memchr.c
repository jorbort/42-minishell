/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbortolo <jbortolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 11:05:45 by jbortolo          #+#    #+#             */
/*   Updated: 2023/05/10 13:36:48 by jbortolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*p;
	unsigned char	d;

	i = 0;
	p = (unsigned char *)s;
	d = (unsigned char)c;
	while (i < n && p[i] != d)
		i++;
	if (i < n && p[i] == d)
		return (&p[i]);
	return (NULL);
}
