/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-anm <juan-anm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 11:46:25 by juan-anm          #+#    #+#             */
/*   Updated: 2023/05/11 11:01:18 by juan-anm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	k;

	if (dstsize <= ft_strlen(dst))
		return (dstsize + ft_strlen(src));
	i = ft_strlen(dst);
	k = ft_strlen(dst);
	j = 0;
	while (src[j] != '\0' && i < dstsize - 1)
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	if (dstsize != 0 && i <= dstsize)
		dst[i] = '\0';
	return (k + ft_strlen(src));
}
/*int main(void)
{
    char src[] = "CCCCCCAAAAAAAAAAAAA";
    char dest[15];
//    char src2[] = "CCCCCCAAAAAAAAAAAAA";

//    char dest2[15];

	unsigned int len = ft_strlcat(dest, src, -1);
//	unsigned int len1 = strlcat(dest2, src2, -1);
    printf("ft_strlcpy result: dest = %s, len = %u\n", dest, len);
//	printf("strlcpy result: dest = %s, len = %u\n", dest2, len1);

 	return 0;
}*/
