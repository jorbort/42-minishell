/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansor_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juanantonio <juanantonio@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 10:45:36 by juanantonio       #+#    #+#             */
/*   Updated: 2023/12/27 15:13:42 by juanantonio      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <includes/minishell.h>

int	ft_search_quote(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\"')
			return (1);
		if (str[i] == '\'')
			return (0);
		i++;
	}
	return (1);
}

char	*ft_get_varname(char *str, int i)
{
	int		j;

	j = 0;
	while ((str[i + j] && ft_isalnum(str[i + j])) || str[i + j] == '_' 
		|| str[i + j] == '?')
		j++;
	return (ft_substr(str, i, j));
}
