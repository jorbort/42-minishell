/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbortolo <jbortolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 14:34:34 by jbortolo          #+#    #+#             */
/*   Updated: 2023/07/17 13:40:58 by jbortolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha(int c)
{
	int	b;

	b = 1;
	if ((c < 'A' || c > 'Z') && (c < 'a' || c > 'z'))
	{
		b = 0;
	}
	return (b);
}