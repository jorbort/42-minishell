/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-anm <juan-anm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 16:06:54 by juan-anm          #+#    #+#             */
/*   Updated: 2023/05/11 11:32:17 by juan-anm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*dest;
	unsigned const char	*source;

	source = (unsigned char *)src;
	dest = (unsigned char *)dst;
	i = 0;
	if (!src && !dst)
		return (NULL);
	if (source < dest)
	{
		i = n;
		while (i > 0)
		{	
			dest[i - 1] = source[i - 1];
		i--;
		}
	}
	else
	{
		ft_memcpy(dst, src, n);
	}
	return (dest);
}

/*#include <string.h>
int main(void)
{

    unsigned char src[] = "hola que tal?";
	unsigned char dest[15];
    unsigned char src1[] = "hola que tal?";
	unsigned char dest1[15];



	ft_memmove(dest1, src1, 13);
    memmove(dest, src, 13);
    printf("Copied string is: %s\n", dest1);
    printf("Copied string is: %s\n", dest);

    return 0;
}*/
