/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-anm <juan-anm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 09:19:19 by juan-anm          #+#    #+#             */
/*   Updated: 2023/05/11 11:55:06 by juan-anm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	const unsigned char	*str;

	str = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (str[i] == (unsigned char)c)
			return ((char *)&str[i]);
	i++;
	}
	return (0);
}

/*int main(void)
{
const void *s = "hola que tal";
int c = 32;

printf("%s\n", ft_memchr(s,c,6));
printf("%s", memchr(s,c,6));
}*/
