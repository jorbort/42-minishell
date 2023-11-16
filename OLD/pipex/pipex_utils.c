/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorge <jorge@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 18:07:13 by jorge             #+#    #+#             */
/*   Updated: 2023/08/27 15:54:51 by jorge            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		tab[i] = NULL;
		i++;
	}
	if (tab)
	{
		free(tab);
		tab = NULL;
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
	close(files->input);
	close(files->output);
}

void	ft_error(char *error)
{
	perror(error);
	exit(1);
}

void	open_files(t_files *files, char **argv)
{
	files->input = open(argv[1], O_RDONLY);
	files->output = open(argv[4], O_TRUNC | O_CREAT | O_WRONLY, 0777);
	if (files->input == -1)
	{
		close(files->output);
		ft_error(OPEN_ERROR);
	}
	if (files->output == -1)
	{
		close(files->input);
		ft_error(OPEN_ERROR);
	}
}
