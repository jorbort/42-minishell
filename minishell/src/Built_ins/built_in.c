/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorgebortolotti <jorgebortolotti@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 13:16:27 by jbortolo          #+#    #+#             */
/*   Updated: 2024/01/02 09:33:52 by jorgebortol      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

void	free_arr(char **arr, char *str)
{
	int	i;

	i = 0;
	while (arr[i] != NULL)
	{
		free(arr[i]);
		i++;
	}
	if (str)
		free(str);
	free(arr);
}

void	is_builtin(t_program *program)
{
	char	**builtin_arr;
	t_cmd	*tmp;
	int		len;
	int		i;
	char	*str;

	str = ft_strdup("cd pwd echo export unset env exit");
	builtin_arr = ft_split(str, 32);
	tmp = program->cmd_list;
	while (tmp != NULL)
	{
		tmp->cmd[0] = ft_strdup_clean(tmp->cmd[0]);
		len = ft_strlen(tmp->cmd[0]);
		i = 0;
		while (builtin_arr[i] != NULL)
		{
			if (ft_strncmp(tmp->cmd[0], builtin_arr[i], len + 1) == 0)
			{
				tmp->built_in = true;
			}
			i++;
		}
		tmp = tmp->next;
	}
	free_arr(builtin_arr, str);
}

void	exec_builtin(t_program *program)
{
	if (program->cmd_list->cmd[0])
	{
		if (strncmp(program->cmd_list->cmd[0], "cd", 2) == 0)
			(*program->exit_code) = change_dir(program, program->cmd_list);
		if (strncmp(program->cmd_list->cmd[0], "pwd", 3) == 0)
			(*program->exit_code) = print_wd(program->data);
		if (strncmp(program->cmd_list->cmd[0], "env", 3) == 0)
			(*program->exit_code) = print_env(program);
		if (strncmp(program->cmd_list->cmd[0], "export", 6) == 0)
			(*program->exit_code) = ft_export(program->cmd_list, program);
		if (strncmp(program->cmd_list->cmd[0], "exit", 6) == 0)
			(*program->exit_code) = ft_exit(program->cmd_list->cmd, program);
		if (strncmp(program->cmd_list->cmd[0], "echo", 4) == 0)
			(*program->exit_code) = ft_echo(program->cmd_list);
		if (strncmp(program->cmd_list->cmd[0], "unset", 6) == 0)
			(*program->exit_code) = ft_unset(program, program->cmd_list);
	}
}

int	find_pwd(t_data *data)
{
	int	i;

	i = 0;
	while (data->envp[i])
	{
		if (!ft_strncmp(data->envp[i], "PWD=", 4))
			data->pwd = ft_substr(data->envp[i],
					4, ft_strlen(data->envp[i]) - 4);
		if (!ft_strncmp(data->envp[i], "OLDPWD=", 7))
			data->prev_pwd = ft_substr(data->envp[i],
					7, ft_strlen(data->envp[i]) - 7);
		i++;
	}
	return (1);
}
