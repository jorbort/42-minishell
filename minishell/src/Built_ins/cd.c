/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbortolo <jbortolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:17:30 by jorge             #+#    #+#             */
/*   Updated: 2023/11/13 10:30:10 by jbortolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

static char	*find_path_res(char *str, t_program *program)
{
	int i;

	i = 0;
	while (program->data->envp[i])
	{
		if(!ft_strncmp(program->data->envp[i], str, t_strlen(str)))
			return (ft_substr(program->data->envp[i], ft_strlen(str),
			ft_strlen(program->data->envp[i]) - ft_strlen(str)));
		i++;
	}
	return (NULL);
}

static int	go_dir(t_program *program, char *str)
{
	char	*tmp;
	int		resul;

	tmp = find_path_res(str, program);
	resul = chdir(tmp);
	ree (tmp);
	if (resul != 0)
	{
		str = ft_substr(str, 0 , ft_strlen(str) - 1);
		ft_putstr_fd(str, STDERR_FILENO);
		free(str);
		ft_putstr_fd(" not set\n", STDERR_FILENO);
	}
	return (resul);
}



static void	change_path_env(t_program *program)
{
	int		i;
	char	*tmp;

	i = 0;
	while (program->data->envp[i])
	{
		if (!ft_strncmp(program->data->envp[i], "pwd=", 4))
		{
			tmp = ft_strjoin("PWD=", program->data->pwd);
			free(program->data->envp[i]);
			program->data->envp[i] = tmp;
		}
		else if (!ft_strncmp("OLDPWD=", program->data->prev_pwd, 7))
		{
			tmp = ft_strjoin("OLDPWD=", program->data->prev_pwd);
			free(program->data->envp[i]);
			program->data->envp[i] = tmp;
		}
		i++;
	}
}

bool	change_dir(t_program *program, t_cmd *cmd_list)
{
	int	res;

	if (!cmd_list->cmd[1])
		res = go_dir(program, "HOME=");
	else if (ft_strncmp(cmd_list->cmd[1], "-", 1))
		res = go_dir(program, "OLDPWD=");
	else 
	{
		res = chdir(cmd_list->cmd[1]);
		if (res != 0)
			ft_error(program, 6);
	}
	if (res != 0)
		return (false);
	change_path(program);
	change_path_env(program);
	return (true);
}
