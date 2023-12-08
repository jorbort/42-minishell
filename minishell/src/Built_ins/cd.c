/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorgebortolotti <jorgebortolotti@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:17:30 by jorge             #+#    #+#             */
/*   Updated: 2023/12/08 16:46:40 by jorgebortol      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

static char	*find_path_res(char *str, t_program *program)
{
	int	i;

	i = 0;
	while (program->data->envp[i])
	{
		if (!ft_strncmp(program->data->envp[i], str, ft_strlen(str)))
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
	free(tmp);
	if (resul != 0)
	{
		str = ft_substr(str, 0, ft_strlen(str) - 1);
		ft_putstr_fd(str, STDERR_FILENO);
		free(str);
		ft_putstr_fd(" not set\n", STDERR_FILENO);
	}
	if (!ft_strncmp(str, "OLDPWD=", 7) && resul == 0)
		ft_printf("%s\n",program->data->prev_pwd);
	return (resul);
}



static void	change_path_env(t_program *program)
{
	int		i;
	char	*tmp;

	i = 0;
	while (program->data->envp[i])
	{
		if (!ft_strncmp(program->data->envp[i], "PWD=", 4))
		{
			tmp = ft_strjoin("PWD=", program->data->pwd);
			free(program->data->envp[i]);
			program->data->envp[i] = tmp;
		}
		else if (!ft_strncmp(program->data->envp[i], "OLDPWD=", 7) && program->data->prev_pwd)
		{
			tmp = ft_strjoin("OLDPWD=", program->data->prev_pwd);
			free(program->data->envp[i]);
			program->data->envp[i] = tmp;
		}
		i++;
	}
}

void	print_cd_error(char *str)
{
	ft_putstr_fd("minishell: cd: ", STDERR_FILENO);
	ft_putstr_fd(str, STDERR_FILENO);
	ft_putstr_fd(": ",STDERR_FILENO);
	perror("");
}

int	change_dir(t_program *program, t_cmd *cmd_list)
{
	int	res;

	if (cmd_list->cmd[1])
		clean_quotes(cmd_list->cmd[1]);
	if (!cmd_list->cmd[1])
		res = go_dir(program, "HOME=");
	else if (ft_strncmp(cmd_list->cmd[1], "-", 1) == 0)
		res = go_dir(program, "OLDPWD=");
	else if (ft_strncmp(cmd_list->cmd[1], "~", 1) == 0)
		res = go_dir(program, "HOME=");
	else
	{
		res = chdir(cmd_list->cmd[1]);
		if (res != 0)
		{
			print_cd_error(cmd_list->cmd[1]);
		}
	}
	if (res != 0)
		return (1);
	change_path(program);
	change_path_env(program);
	return (0);
}
