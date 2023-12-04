/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_executor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbortolo <jbortolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 09:23:12 by jorge             #+#    #+#             */
/*   Updated: 2023/12/04 11:48:01 by jbortolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

static void	dup_cmd(t_cmd *cmd_list, t_program *program, int *end, int fd_in)
{
	if (cmd_list->prev && dup2(fd_in, STDIN_FILENO) < 0)
		ft_error(program, 8);
	close(end[0]);
	if (cmd_list->next && dup2(end[1], STDOUT_FILENO) < 0)
		ft_error(program, 8);
	close(end[1]);
	if (cmd_list->prev)
		close(fd_in);
	handle_cmd(cmd_list, program);
}

static int	pipe_wait(int *pid, int amount, t_program *program)
{
	int	i;
	int	status;

	i = 0;
	while (i < amount)
	{
		waitpid(pid[i], &status, 0);
		i++;
	}
	waitpid(pid[i], &status, 0);
	if (WIFEXITED(status))
		program->exit_code = WEXITSTATUS(status);
	return (0);
}

static int	ft_fork(t_program *program, int *end, int fd_in, t_cmd *cmd_list)
{
	static int	i = 0;

	program->data->pid[i] = fork();
	if (program->data->pid[i] < 0)
		ft_error(program, 7);
	if (program->data->pid[i] == 0)
		dup_cmd(cmd_list, program, end, fd_in);
	i++;
	return (0);
}

int	ft_executor(t_program *program)
{
	int	end[2];
	int	fd_in;

	fd_in = STDIN_FILENO;
	while (program->cmd_list)
	{
		if (program->cmd_list->next)
			pipe(end);
		set_heredoc(program, program->cmd_list);
		ft_fork(program, end, fd_in, program->cmd_list);
		close(end[1]);
		if (program->cmd_list->prev)
			close(fd_in);
		fd_in = check_fd_heredoc(program, end, program->cmd_list);
		if (program->cmd_list->next)
			program->cmd_list = program->cmd_list->next;
		else
			break ;
	}
	pipe_wait(program->data->pid, program->data->pipes, program);
	program->cmd_list = ft_first(program->cmd_list);
	return (0);
}
