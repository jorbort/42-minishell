/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juanantonio <juanantonio@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 11:23:40 by juanantonio       #+#    #+#             */
/*   Updated: 2023/10/26 12:57:25 by juanantonio      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	ft_isspchar(char c)
{
	if (ft_isspace(c) || ft_isapipe(c) || ft_isaquote(c))
		return (1);
	else
		return (0);
}

int	dupstrlen(char *s, int i)
{
	char	quote;

	quote = 0;
	if (ft_isapipe(s[i]))
		i++;
	else if (ft_isaquote(s[i]))
	{
		quote = s[i];
		i++;
		while (s[i] != quote && s[i]) 
			i++;
		if (s[i] == quote)
			i++;
	}
	else
	{
		while (!ft_isspchar(s[i]) && s[i] != 0)
			i++;
	}
	return (i);
}
