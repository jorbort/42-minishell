/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-anm <juan-anm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 10:48:42 by juan-anm          #+#    #+#             */
/*   Updated: 2023/05/11 11:46:20 by juan-anm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int			i;

	i = 0;
	while (s[i] != 0)
	{	
		if (s[i] == (unsigned char)c)
			return ((char *)&(s[i]));
	i++;
	}
	if ((unsigned char)c == '\0')
		return ((char *)&(s[i]));
	else
		return (NULL);
}	

/*#include <stdio.h>
#include <string.h>
int main(void)
{

	printf("%p\n", ft_strchr("hola",0));
	printf("%p", strchr("hola", 0));

}*/
