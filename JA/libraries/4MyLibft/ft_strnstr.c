/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-anm <juan-anm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 12:48:39 by juan-anm          #+#    #+#             */
/*   Updated: 2023/05/10 14:55:00 by juan-anm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (needle[i] == 0)
		return ((char *)&haystack[0]);
	while (haystack[i] != 0 && i < len)
	{
		j = 0;
		if (haystack[i] == needle[j])
		{
			while (haystack[i + j] == needle[j] && (i + j) < len
				&& (haystack[i + j] != 0 || needle[j] != 0))
			{
			j++;
			}
			if (needle[j] == 0)
				return ((char *)&haystack[i]);
		}
	i++;
	}
	return (0);
}

/*#include <string.h>
int main(void)
{
 	const char *largestring = "Foo Ba bar Baz";
 	const char *smallstring = "Bar";

    printf("%s\n",ft_strnstr(largestring, smallstring, 10));
    printf("%s",strnstr(largestring, smallstring, 10));

}*/
