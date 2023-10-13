/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-anm <juan-anm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 11:16:14 by juan-anm          #+#    #+#             */
/*   Updated: 2023/05/09 13:35:18 by juan-anm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	cont;

	cont = 0;
	i = 0;
	while (src[cont] != 0)
		cont++;
	if (size == 0)
		return (cont);
	while (src[i] != 0 && i < (size - 1))
	{
		dest[i] = src[i];
	i++;
	}
	dest[i] = 0;
	return (cont);
}

/*#include <stdio.h>
#include <string.h>

int main(void)
{
    char src[] = "";
    char dest[15];
    unsigned int len = strlcpy(dest, src, sizeof(dest));
    printf("ft_strlcpy result: dest = %s, len = %u\n", dest, len);
    return 0;
}*/
