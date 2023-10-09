/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-anm <juan-anm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 09:30:28 by juan-anm          #+#    #+#             */
/*   Updated: 2023/05/09 16:02:06 by juan-anm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t		i;
	const char	*str1;
	const char	*str2;

	str1 = (const char *)s1;
	str2 = (const char *)s2;
	i = 0;
	if (n != 0)
	{
		while (str1[i] == str2[i] && (i < n - 1))
		{
		i++;
		}
		return ((unsigned char)str1[i] - (unsigned char)str2[i]);
	}
	return (0);
}

/*int main(void)
{
	const void *s1 = "hola que ta2";
	const void *s2 = "hola que@ ta";
	
	printf("%i\n", ft_memcmp(s1, s2 ,12));
	printf("%d", memcmp(s1, s2, 12));
}*/
