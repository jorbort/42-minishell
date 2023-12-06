/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_general.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juanantonio <juanantonio@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 18:22:04 by jorge             #+#    #+#             */
/*   Updated: 2023/12/06 15:52:06 by juanantonio      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

bool	invalid_unsetchar(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '=' || str[i] == '?' || str[i] == '!' || str[i] == '.'
			|| str[i] == '+' || str[i] == '}' || str[i] == '{' || str[i] == '-'
			|| str[i] == 92 || str[i] == '[' || str[i] == ']' || str[i] == '@'
			|| str[i] == '*' || str[i] == '#' || str[i] == '^' || str[i] == '~')
			return (true);
		i++;
	}
	return (false);
}

void	free_double_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i] != NULL)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	arr = NULL;
}

char	**ft_arrdup(char **arr)
{
	char	**rtn;
	size_t	i;

	i = 0;
	while (arr[i] != NULL)
		i++;
	rtn = ft_calloc(sizeof(char *), i + 1);
	if (!rtn)
		return (NULL);
	i = 0;
	while (arr[i] != NULL)
	{
		rtn[i] = ft_strdup(arr[i]);
		if (rtn[i] == NULL)
		{
			free_double_arr(rtn);
			return (rtn);
		}
		i++;
	}
	arr[i] = NULL;
	return (rtn);
}

void	change_path(t_program *program)
{
	char	*tmp;

	tmp = ft_strdup(program->data->pwd);
	free(program->data->prev_pwd);
	program->data->prev_pwd = tmp;
	free(program->data->pwd);
	program->data->pwd = getcwd(NULL, PATH_MAX);
}
