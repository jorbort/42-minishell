/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-anm <juan-anm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 12:38:55 by juan-anm          #+#    #+#             */
/*   Updated: 2023/05/09 11:10:35 by juan-anm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*str;

	str = b;
	i = 0;
	while (i < len)
	{
		str[i] = c;
		i++;
	}
	return (str);
}

/*#include <string.h>
int main(void)
{
	char str[50];  
	printf("%s \n", ft_memset(str, 0, 50));
	printf("%s \n", memset(str, 0, 50));
}*/
