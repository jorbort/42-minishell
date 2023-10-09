/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-anm <juan-anm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 12:23:08 by juan-anm          #+#    #+#             */
/*   Updated: 2023/05/09 15:40:49 by juan-anm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n != 0)
	{
		while ((s1[i] != 0 || s2[i] != 0) && i < n)
		{
			if (s1[i] != s2[i])
				return ((unsigned char)s1[i] - (unsigned char)s2[i]);
			i++;
		}
	}
	return (0);
}

/*#include <string.h>
int main(void)
{
	printf("%i",ft_strncmp("hOla", "hoLa", 0));
	printf("%i",strncmp("hOla", "hoLa", 0));
}*/
