/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-anm <juan-anm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 12:49:30 by juan-anm          #+#    #+#             */
/*   Updated: 2023/05/11 11:54:13 by juan-anm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	ptr = malloc(count * size);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, count * size);
	return (ptr);
}

/*#include <unistd.h>	
#include <stdio.h>
#include <stdlib.h>	
int main(void)
{
	// printf ("%s\n", ft_calloc(10, 1)) ;
	 write(1, ft_calloc(10, 1), 10);
	 write(1, "\n", 1);
	 write(1, calloc(10, 1), 10);
	 write(1, "\n", 1);

	 //printf ("%s\n", calloc(10,  1)); 

    return (0);
}*/
