/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorge <jorge@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 08:21:56 by jorge             #+#    #+#             */
/*   Updated: 2024/01/04 09:43:36 by jorge            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

static int	find_cmd(t_cmd *cmd_list, t_program *program)
{
	int		i;
	char	*path;

	i = 0;
	if (!program->data->paths)
		return (cmd_not_found(cmd_list->cmd[0]));
	cmd_list->cmd = rejoin_str(cmd_list->cmd);
	if (!access(cmd_list->cmd[0], F_OK))
		execve(cmd_list->cmd[0], cmd_list->cmd, program->data->envp);
	while (program->data->paths[i])
	{
		path = ft_strjoin(program->data->paths[i], cmd_list->cmd[0]);
		if (!access(path, F_OK))
			execve(path, cmd_list->cmd, program->data->envp);
		free(path);
		i++;
	}
	return (cmd_not_found(cmd_list->cmd[0]));
}

void	handle_cmd(t_cmd *cmd_list, t_program *program)
{
	int	exit_status;

	exit_status = 0;
	if (cmd_list->redirection)
		if (check_redirs(cmd_list))
			exit(1);
	if (program->data->pipes > 0 && cmd_list->built_in == true)
	{
		exec_builtin(program);
		exit_status = (*program->exit_code);
	}
	else if (cmd_list->cmd[0][0])
		exit_status = find_cmd(cmd_list, program);
	exit(exit_status);
}

static int	exec_single_cmd(t_cmd *cmd_list, t_program *program)
{
	int	pid;
	int	status;

	if (!cmd_list)
		return ((*program->exit_code) = 127);
	set_heredoc(program, cmd_list);
	if (cmd_list->built_in)
	{
		if (cmd_list->redirection)
		{
			if (check_redirs(cmd_list))
				return ((*program->exit_code) = 1);
		}
		exec_builtin(program);
		return (0);
	}
	pid = fork();
	if (pid < 0)
		ft_error(program, 7);
	if (pid == 0)
		handle_cmd(cmd_list, program);
	waitpid(pid, &status, 0);
	if (WIFEXITED(status))
		(*program->exit_code) = WEXITSTATUS(status);
	return (0);
}

int	handle_execution(t_program *program)
{
	int	saved_stdout;
	int	saved_stdin;

	saved_stdout = dup(1);
	saved_stdin = dup(0);
	ft_expand(program);
	is_builtin(program);
	if (program->data->pipes == 0)
	{
		exec_single_cmd(program->cmd_list, program);
		dup2(saved_stdout, 1);
		dup2(saved_stdin, 0);
		close(saved_stdout);
		close(saved_stdin);
		return ((*program->exit_code));
	}
	else
	{
		program->data->pid = ft_calloc(sizeof(int), program->data->pipes + 2);
		if (!program->data->pid)
			return (ft_error(program, 1));
		ft_executor(program);
	}
	return (0);
}
