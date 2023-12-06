/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juanantonio <juanantonio@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 17:30:21 by jorge             #+#    #+#             */
/*   Updated: 2023/12/06 13:56:03 by juanantonio      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

int	export_error(char *c)
{
	ft_putstr_fd("minishell: export: ", STDERR_FILENO);
	if (c)
	{
		ft_putchar_fd('`',STDERR_FILENO);
		ft_putcleanstr_fd(c, STDERR_FILENO);
		ft_putstr_fd("\': ", STDERR_FILENO);
	}
	ft_putendl_fd("not a valid identifier", STDERR_FILENO);
	return (1);
}

size_t	equal_sign(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '=')
			return (i + 1);
		i++;
	}
	return (0);
}

char	*trim_quotes(char *str, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == c)
		{
			j = 0;
			while (str[i + j] == c)
				j++;
			ft_strlcpy(&str[i], &str[i + j], strlen(str) - i);
		}
		i++;
	}
	return (str);
}
int	check_valid_char(char c)
{
	if (c == '|' || c == '<' || c == '>' || c == '[' || c == ']'
	|| c == ' ' || c == ',' || c == '.'	|| c == ':' || c == '/'
	|| c == '{' || c == '}' || c == '+' || c == '^' || c == '%'
	|| c == '#' || c == '@' || c == '!'	|| c == '~'	|| c == '='
	|| c == '-' || c == '?' || c == '&' || c == '*')
		return (1);
	else
		return (0);
}