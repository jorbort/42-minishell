/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbortolo <jbortolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 12:13:06 by jbortolo          #+#    #+#             */
/*   Updated: 2023/05/10 14:24:06 by jbortolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	len;
	size_t	j;
	size_t	res_d;
	size_t	res_s;

	len = ft_strlen(dst);
	j = 0;
	res_d = ft_strlen(dst);
	res_s = ft_strlen(src);
	if (dstsize < 1)
		return (ft_strlen(src) + dstsize);
	while (src[j] && len < dstsize -1)
	{
		dst[len] = src[j];
		j++;
		len++;
	}
	dst[len] = '\0';
	if (dstsize < ft_strlen(dst))
		return (res_s + dstsize);
	else
		return (res_d + res_s);
}
