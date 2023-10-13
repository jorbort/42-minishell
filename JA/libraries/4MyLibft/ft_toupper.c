/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-anm <juan-anm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 14:30:51 by juan-anm          #+#    #+#             */
/*   Updated: 2023/05/09 11:09:10 by juan-anm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	else
		return (c);
}

/*#include <ctype.h>
#include <stdio.h>
int main(void)
{

	char c,b;
	c = ft_toupper(65);
	b = toupper(65);
	printf("%c", c);
	printf("%c", b);
}*/
