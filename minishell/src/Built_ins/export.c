/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorge <jorge@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 12:44:41 by jbortolo          #+#    #+#             */
/*   Updated: 2023/11/30 17:31:33 by jorge            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

int	var_exist(t_program *program, char *str)
{
	int	i;

	i = 0;
	if (str[equal_sign(str)] == '\"')
		trim_quotes(str,'\"');
	if (str[equal_sign(str)] == '\'')
		trim_quotes(str, '\'');
	while (program->data->envp)
	{
		if (ft_strncmp(program->data->envp[i],
						str, equal_sign(program->data->envp[i])) == 0)
		{
			free(program->data->envp[i]);
			program->data->envp[i] = ft_strdup(str);
			return (1);
		}
		i++;
	}
	return (0);
}

int	check_parameter(char *str)
{
	int	i;

	i = 0;
	if (ft_isdigit(str[0]))
		return (export_error(str));
	if (equal_sign(str) == 0)
		return (1);
	if (str[0] != '=')
		return (export_error(str));
	while (str[i] != '=')
	{
		if (invalid_unsetchar(str[i]))
			return (export_error(str));
		i++;
	}
	return (0);
}

char	**whileloop_add_var(char **arr, char **rtn, char *str)
{
	int	i;

	i = 0;
	while (arr[i] != NULL)
	{
		if (arr[i + 1] == NULL)
		{
			rtn[i] = ft_strdup(str);
			rtn[i + 1] = ft_strdup(arr[i]);
		}
		else 
			rtn[i] = ft_strdup(arr[i]);
		if (rtn[i] == NULL)
		{
			free_double_arr(rtn);
			return (rtn);
		}
		i++;
	}
	return (rtn);
}

char	**add_var(char **arr, char *str)
{
	char	**rtn;
	size_t	i;

	i = 0;
	if (str[equal_sign(str)] == '\"')
		trim_quotes(str,'\"');
	if (str[equal_sign(str)] == '\'')
		trim_quotes(str, '\'');
	while (arr[i] != NULL)
		i++;
	rtn = ft_calloc(sizeof(char *), i+2);
	if (!rtn)
		return (NULL);
	i = 0;
	whileloop_add_var(arr, rtn, str);
	return (rtn);
}

int	ft_export(t_cmd *cmd_list, t_program *program)
{
	char **tmp;
	int i = 0;

	i = 1;
	if (!cmd_list->cmd[1] || cmd_list->cmd[1][0] == '\0')
		print_env(program);
	else 
	{
		while (cmd_list->cmd[i])
		{
			if (check_input(cmd_list->cmd[i]) == 0
					&& var_exist(program, cmd_list->cmd[i]) ==0)
			{
				if (cmd_list->cmd[i])
				{
					tmp = add_var(program->data->envp, cmd_list->cmd[i]);
					free_double_arr(program->data->envp);
					program->data->envp = tmp;
				}
			}
			i++;
		}
	}
	return (0);
}
