/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorge <jorge@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 18:13:37 by jorge             #+#    #+#             */
/*   Updated: 2023/08/26 01:26:19 by jorge            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static void	first_child(char **argv, int i, t_files *files, char **env)
{
	t_cmd	*cmd;

	cmd = find_cmd(argv[i], env, files);
	close(files->fd[0]);
	close(files->output);
	dup2(files->fd[1], STDOUT_FILENO);
	close(files->fd[0]);
	execve(cmd->path.path, (char *const *) cmd->cmd, env);
	free_struct(cmd);
}

static void	second_child(char **argv, int argc, t_files *files, char **env)
{
	t_cmd	*cmd;

	if (pipe(files->fd) < 0)
		close_exit(PIPE_ERROR, files);
	files->pid = fork();
	if (files->pid == -1)
		close_exit(FORK_ERROR, files);
	else if (files->pid == 0)
	{
		cmd = find_cmd(argv[argc - 2], env, files);
		close(files->fd[0]);
		close(files->fd[1]);
		dup2(files->output, STDIN_FILENO);
		close(files->output);
		execve(cmd->path.path, (char *const *)cmd->cmd, env);
		free_struct(cmd);
	}
	close_fd(files);
	waitpid(files->pid, NULL, 0);
}

static void	command_loop(int argc, char **argv, char **env, t_files *files)
{
	int	i;

	i = 2;
	dup2(files->input, STDIN_FILENO);
	close(files->input);
	if (ft_strncmp("here_doc", argv[1], 8) == 0)
		i = 3;
	while (i < argc - 2)
	{
		if (pipe(files->fd) < 0)
			close_exit(PIPE_ERROR, files);
		files->pid = fork();
		if (files->pid == -1)
			close_exit(FORK_ERROR, files);
		else if (files->pid == 0)
			first_child(argv, i, files, env);
		else
		{
			close(files->fd[1]);
			dup2(files->fd[0], STDIN_FILENO);
			close(files->fd[0]);
		}
		i++;
	}
	second_child(argv, argc, files, env);
}

static void	open_heredoc(char **argv, int argc, t_files *files)
{
	char	*str;
	int		temp_file;

	if (argc < 6)
		ft_error(ARG_NUM_ERROR);
	temp_file = open(".here_doc", O_TRUNC | O_CREAT | O_WRONLY, 0644);
	while (save_next_line(0, &str))
	{
		if ((ft_strlen(str) == ft_strlen(argv[2]) + 1)
			&& (ft_strncmp(str, argv[2], ft_strlen(argv[2])) == 0))
		{
			free(str);
			break ;
		}
		else
			write(temp_file, str, ft_strlen(str));
		free(str);
	}
	close(temp_file);
	files->input = open(".here_doc", O_RDONLY);
	files->output = open(argv[argc - 1], O_APPEND | O_CREAT | O_WRONLY, 0644);
}

int	main(int argc, char **argv, char **env)
{
	t_files	files;

	if (argc < 5)
		ft_error(ARG_NUM_ERROR);
	if (ft_strncmp("here_doc", argv[1], 8) == 0)
		open_heredoc(argv, argc, &files);
	else
	{
		files.input = open(argv[1], O_RDONLY);
		files.output = open(argv[argc -1], O_TRUNC | O_CREAT | O_WRONLY, 0644);
	}
	open_errors(&files);
	command_loop(argc, argv, env, &files);
	if (ft_strncmp("here_doc", argv[1], 8) == 0)
		unlink(".here_doc");
	return (0);
}
