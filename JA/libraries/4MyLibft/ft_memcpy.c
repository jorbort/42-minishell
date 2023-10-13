/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-anm <juan-anm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 16:06:54 by juan-anm          #+#    #+#             */
/*   Updated: 2023/05/11 11:17:25 by juan-anm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*dest;
	unsigned const char	*source;

	source = src;
	dest = dst;
	i = 0;
	if (!dst && !src)
		return (NULL);
	while (i < n)
	{
		dest[i] = source[i];
	i++;
	}
	return (dest);
}

/*#include <string.h>

int main(void)
{

    char src[] = "Hello, world!";
    char dest[5];

	ft_memcpy(dest, src, 4);
//    memcpy(dest, src, 13);
    printf("Copied string is: %s\n", dest);

    return 0;
}*/
