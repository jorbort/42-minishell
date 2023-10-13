/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-anm <juan-anm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 12:38:55 by juan-anm          #+#    #+#             */
/*   Updated: 2023/05/09 11:07:58 by juan-anm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*str;

	str = s;
	i = 0;
	while (i < n)
	{
		str[i] = 0;
		i++;
	}	
}

/*#include <string.h>
int main(void)
{
	char str[50] = "Hello World";
	
	printf("%s \n", str);
	ft_bzero(str, 0);
//	bzero(str, 10);
	printf("%s \n", str);
}*/
