/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbortolo <jbortolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 15:55:17 by jbortolo          #+#    #+#             */
/*   Updated: 2023/05/09 10:25:46 by jbortolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isascii(int c)
{
	int	b;

	b = 0;
	if (c >= 0 && c <= 127)
	{
		b = 1;
	}
	return (b);
}