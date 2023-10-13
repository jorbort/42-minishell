/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-anm <juan-anm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 11:31:09 by juan-anm          #+#    #+#             */
/*   Updated: 2023/05/11 12:04:37 by juan-anm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int			i;
	const char	*str;
	char		*dupstr;

	str = s1;
	i = 0;
	dupstr = malloc(ft_strlen(s1) * sizeof(char) + 1);
	if (!dupstr)
		return (NULL);
	while (str[i] != 0)
	{	
		dupstr[i] = str[i];
	i++;
	}
	dupstr[i] = 0;
	return (dupstr);
}

/*int main(void)
{

char str[15] = "hola que tal?";

printf("%s", ft_strdup(str));

}*/
