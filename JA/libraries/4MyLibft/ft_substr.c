/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-anm <juan-anm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 11:29:06 by juan-anm          #+#    #+#             */
/*   Updated: 2023/05/11 13:08:50 by juan-anm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*substr;

	if (!s)
		return (NULL);
	i = ft_strlen(s);
	if (i < start)
		return (ft_strdup(""));
	if (start + len > i)
		len = i - start;
	substr = (char *)malloc(sizeof(char) * (len + 1));
	if (!substr)
		return (NULL);
	if (start < ft_strlen(s))
		ft_memcpy(substr, &s[start], len);
	substr[len] = '\0';
	return (substr);
}

/*int main(void)
{
	char str[15] = "hola que tal?";

	printf("%s\n", ft_substr(str, 5, 3));
//	printf("%d", substr(str, 5, 9));
}*/
