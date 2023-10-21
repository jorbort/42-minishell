/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isapipe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juanantonio <juanantonio@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 10:27:53 by juan-anm          #+#    #+#             */
/*   Updated: 2023/10/21 12:02:18 by juanantonio      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isapipe(char c)
{
	//if (c == 124 || c == 60 || c == 62 || c == 34 || c == 39)
	if (c == 124 || c == 60 || c == 62)
		return (1);
	else
		return (0);
}