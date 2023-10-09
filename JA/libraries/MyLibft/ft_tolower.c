/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-anm <juan-anm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 14:45:10 by juan-anm          #+#    #+#             */
/*   Updated: 2023/05/09 11:09:15 by juan-anm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	else
		return (c);
}

/*#include <ctype.h>
#include <stdio.h>
int main(void)
{

	char c,b;
	c = ft_tolower(65);
	b = tolower(65);
	printf("%c", c);
	printf("%c", b);
}*/
