/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorge <jorge@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 08:21:56 by jorge             #+#    #+#             */
/*   Updated: 2023/12/01 17:36:00 by jorge            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

int	find_cmd(t_cmd *cmd_list, t_program * program)
{
	int		i;
	char	*path;

	i = 0;
	cmd_list->cmd = rejoin_str(cmd_list->cmd);
	if (!access(cmd_list->cmd[0], F_OK))
		execve(cmd_list->cmd[0],cmd_list->cmd,program->data->envp);
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
	int	exit_code;

	exit_code = 0;
	if (cmd_list->redirection)
		if (check_redirs(cmd_list))//function -->to-do
			exit(1);
	if (cmd_list->cmd[0][0])
		exit_code = find_cmd(cmd_list, program);
	exit(exit_code);
}


void	single_cmd(t_cmd *cmd_list, t_program *program)
{
	int	pid;
	int status;

	if (cmd_list->built_in == true)
	{
		exec_builtin(program);
		return ;
	}
	//set_heredoc(program, cmd_list) --> to-do
	pid = fork();
	if (pid < 0)
		ft_erorr(program, 7);
	if (pid == 0)
		handle_cmd(cmd_list, program);
	waitpid(pid, &status, 0);
	if (WIFEXITED(status))
		program->exit_code = WEXITSTAUS(status);
}


int	handle_execution(t_program *program)
{
	ft_expand(program);
	is_builtin(program);
	if (program->data->pipes = 0)
		exec_single_cmd(program->cmd_list, program);
	else
	{
		program->data->pid = ft_calloc(sizeof(int), program->data->pipes + 2);
		if (!program->data->pid)
			return (ft_error(program, 1));
		ft_executor(program);
	}
	return (0);
}