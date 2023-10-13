/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-anm <juan-anm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 11:29:08 by juan-anm          #+#    #+#             */
/*   Updated: 2023/05/11 11:53:44 by juan-anm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = ft_strlen(s);
	while (i >= 0)
	{	
		if (s[i] == (unsigned char)c)
			return ((char *)&(s[i]));
	i--;
	}
	return (0);
}	

/*#include <stdio.h>
#include <string.h>
int main(void)
{

	printf("%p\n", ft_strrchr("hoola",60));
	printf("%p", strrchr("hoola",60));

}*/
