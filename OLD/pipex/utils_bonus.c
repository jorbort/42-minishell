/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorge <jorge@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 18:01:30 by jorge             #+#    #+#             */
/*   Updated: 2023/08/25 18:12:48 by jorge            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	open_errors(t_files *files)
{
	if (files->input < 0 && files->output < 0)
		ft_error(OPEN_ERROR);
	if (files->input < 0)
	{
		close(files->output);
		ft_error(OPEN_ERROR);
	}
	if (files->output < 0)
	{
		close(files->input);
		ft_error(OPEN_ERROR);
	}
}

void	free_struct(t_cmd *cmd)
{
	if (cmd->path.path)
		free(cmd->path.path);
	free_tab(cmd->path.env);
	free_tab(cmd->cmd);
	if (cmd)
		free(cmd);
}

void	close_fd(t_files *files)
{
	close(files->fd[0]);
	close(files->fd[1]);
	close(files->output);
}

void	ft_error(char *error)
{
	perror(error);
	exit(1);
}

void	close_exit(char *error, t_files *files)
{
	close_fd(files);
	ft_error(error);
}
