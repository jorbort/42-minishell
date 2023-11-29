/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juanantonio <juanantonio@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 00:57:41 by jorge             #+#    #+#             */
/*   Updated: 2023/11/29 13:55:03 by juanantonio      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

static int	ft_unsetcomp(char *s1, char *s2)
{
	int	i;

	i = 0;
	if (!s2)
		return (-1);
	while (s2[i] && s2[i + 1] && s2[i + 1] != '=' && s1[i] && s1[i] == s2[i])
		i++;
	return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
}

static bool	iter_var(char **arr, char *str)
{
	int	i;

	i = 0;
	while (arr[i] != NULL)
	{
		if (ft_unsetcomp(str, arr[i]) == 0)
		{
			free(arr[i]);
			arr[i] = NULL;
			break ;
		}
	}
	return (true);
}

static bool	unset_fail(t_cmd *cmd_list)
{
	int	i;

	i = 0;
	if (!cmd_list->cmd[1])
	{
		ft_putendl_fd("minishell: unset: not enough arguments", STDERR_FILENO);
		return (false);
	}
	if (invalid_unsetchar(cmd_list->cmd[i]))
	{
		ft_putstr_fd("minishell : unset : '", STDERR_FILENO);
		ft_putstr_fd(cmd_list->cmd[1], STDERR_FILENO);
		ft_putendl_fd("' : not a valid identifier", STDERR_FILENO);
		return (false);
	}
	return (true);
}

int	ft_unset(t_program *program, t_cmd *cmd_list)
{
	if (unset_fail(cmd_list) == false)
		return (1);
	else
		iter_var(program->data->envp, cmd_list->cmd[1]);
	return (0);
}
