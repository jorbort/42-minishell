/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-anm <juan-anm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 11:23:40 by juanantonio       #+#    #+#             */
/*   Updated: 2023/11/13 14:09:52 by juan-anm         ###   ########.fr       */
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
	{
		while (ft_isapipe(s[i]))
			i++;
	}
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
